#include "Visitor.h"

#include <iostream>

#include "llvm/ADT/APInt.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Verifier.h"

#include "ast/Ast.h"
#include "ast/AstTypes.h"
#include "driver/rang.hpp"

using namespace AST;
using namespace Ni;

Visitor::Visitor(Module* module_arg) : module(std::unique_ptr<Module> (module_arg)),
	builder(std::unique_ptr<IRBuilder<> >(new IRBuilder<>(module->getContext())))
{

}

bool Visitor::EnterContext()
{
	contexts.push(ctx);
	ctx = new std::vector<llvm::Value*>();
	if(ctx == 0)
		return false;
	return true;
}

bool Visitor::LeaveContext()
{
	if(contexts.empty())
		return false;
	ctx = contexts.top(); contexts.pop();
	return true;
}

ASTNode* Ni::Visitor::Visit(ASTNode *node, bool visit)
{
	if(visit)
		if(node != NULL)
			node->accept(*this);
		else
			std::cout << "Error node is null" << std::endl;
	processedNodes.push_back(node);
	std::cout << "Pushing Node" << "\n";
	return node;
}

Visitor::~Visitor()
{
	std::cout << "Removing nodes from memory" << "\n";	for(ASTNode* i : processedNodes)
	{
		delete i;
	}
	while(!contexts.empty())
	{
		std::vector<llvm::Value*>* i = contexts.top();
		contexts.pop();
		delete i;
	}
}

void Visitor::NodeVisit(IntNode &node)
{
	valueStack.push(llvm::ConstantInt::get(llvm::Type::getInt64Ty(module->getContext()), node.value, true));
}
void Visitor::NodeVisit(DoubleNode &node)
{
	valueStack.push(llvm::ConstantFP::get(llvm::Type::getDoubleTy(module->getContext()), node.value));
}

void Visitor::NodeVisit(StringNode &node)
{
	valueStack.push(llvm::ConstantDataArray::get(module->getContext(), llvm::ArrayRef<uint8_t>(reinterpret_cast<const unsigned char*>(node.value.c_str()), node.value.length())));
}

void Visitor::NodeVisit(BoolNode &node)
{
	valueStack.push(llvm::ConstantInt::get(llvm::Type::getInt1Ty(module->getContext()), node.value, true));
}

void Visitor::NodeVisit(DeclarationNode &node)
{
	std::cout << "Decl" << "\n";
	*this->Visit(node.val, true);
	llvm::Value* initValue = valueStack.top();
	valueStack.pop();
	if(node.global)
	{
		if(node.varType == Types::INT)
		{
			module->getOrInsertGlobal(node.varName, builder->getInt64Ty());
			llvm::GlobalVariable* glob = module->getGlobalVariable(node.varName);
			glob->setLinkage(llvm::GlobalValue::CommonLinkage);
			glob->setAlignment(4);
			glob->setInitializer(llvm::dyn_cast<llvm::ConstantInt>(initValue));
		}
		if(node.varType == Types::DOUBLE)
        {
            module->getOrInsertGlobal(node.varName, builder->getDoubleTy());
            llvm::GlobalVariable* glob = module->getGlobalVariable(node.varName);
            glob->setLinkage(llvm::GlobalValue::CommonLinkage);
            glob->setAlignment(4);
            glob->setInitializer(llvm::dyn_cast<llvm::ConstantFP>(initValue));
        }
		if(node.varType == Types::BOOL)
        {
            module->getOrInsertGlobal(node.varName, builder->getInt1Ty());
            llvm::GlobalVariable* glob = module->getGlobalVariable(node.varName);
            glob->setLinkage(llvm::GlobalValue::CommonLinkage);
            glob->setAlignment(4);
            glob->setInitializer(llvm::dyn_cast<llvm::ConstantInt>(initValue));
        }
		if(node.varType == Types::STRING)
        {
			llvm::ConstantDataArray* data = llvm::dyn_cast<llvm::ConstantDataArray>(initValue);
            module->getOrInsertGlobal(node.varName, data->getType());
            llvm::GlobalVariable* glob = module->getGlobalVariable(node.varName);
            glob->setLinkage(llvm::GlobalValue::CommonLinkage);
            glob->setAlignment(4);
            glob->setInitializer(llvm::dyn_cast<llvm::ConstantDataArray>(initValue));
        }
	}
	else
	{
		std::cout << "I Was Run" << "\n";
		std::cout << node.val << "\n";
		if(node.varType == Types::INT)
		{
			std::cout << "creating alloca" << "\n";
			llvm::Value* alloca = builder->CreateAlloca(llvm::Type::getInt64Ty(module->getContext()),0, node.varName);
			builder->CreateStore(initValue, alloca);
		}
		if(node.varType == Types::DOUBLE)
        {
			std::cout << "DOUBLE" << "\n";
        }
		if(node.varType == Types::BOOL)
        {
			std::cout << "BOOL" << "\n";
        }
		if(node.varType == Types::STRING)
        {
			std::cout << "STRING" << "\n";
        }
	}

}

void Visitor::NodeVisit(BinOpNode &node)
{
	*this->Visit(node.lhs, true);
	*this->Visit(node.rhs, true);
	llvm::Value* rhs = valueStack.top();
	valueStack.pop();
	llvm::Value* lhs = valueStack.top();
	valueStack.pop();
	llvm::Value* res;
	bool i = false;
	if(rhs->getType()->getTypeID() == llvm::Type::TypeID::IntegerTyID && lhs->getType()->getTypeID()  == llvm::Type::TypeID::IntegerTyID)
		i = true;
	if(node.op == "+")
	{
		if(i) res = builder->CreateAdd(lhs, rhs, "addtmp");
		else res = builder->CreateFAdd(lhs, rhs, "addtmp");
	}
	else if(node.op == "-")
	{
		if(i) res = builder->CreateSub(lhs, rhs, "subtmp");
		else res = builder->CreateFSub(lhs, rhs, "subtmp");
	}
	else if(node.op == "*")
	{
		if(i) res = builder->CreateMul(lhs, rhs, "multmp");
		else res = builder->CreateFMul(lhs, rhs, "multmp");
	}
	else if(node.op == "/")
	{
		res = builder->CreateFDiv(lhs, rhs, "divtmp");
	}
	valueStack.push(res);
}

llvm::Type* ASTTypeToLLVMType(AST::Types ty, llvm::LLVMContext &context)
{
	//Will cause segfault if type isnt one of the following.
	switch(ty)
	{
		case Types::BOOL:
			return llvm::Type::getInt1Ty(context);
		case Types::DOUBLE:
			return llvm::Type::getDoubleTy(context);
		case Types::INT:
			return llvm::Type::getInt64Ty(context);
		case Types::STRING:
			return llvm::Type::getInt8PtrTy(context);
		case Types::VOID:
			return llvm::Type::getVoidTy(context);
	}
}

void Visitor::NodeVisit(FunctionNode &node)
{
	llvm::Type* resType = ASTTypeToLLVMType(node.ty, module->getContext());
	llvm::FunctionType* fnType;
	if(node.args != NULL)
	{
		std::vector<llvm::Type*> tys = std::vector<llvm::Type*>();
		for(auto *i : static_cast<ArgsNode*>(node.args)->args)
			tys.push_back(ASTTypeToLLVMType(i->ty, module->getContext()));
		fnType = llvm::FunctionType::get(resType, tys, false);
	}
	else
		fnType = llvm::FunctionType::get(resType, false);
	llvm::Function* fn;
	if(node.pub)
		fn = llvm::Function::Create(fnType, llvm::Function::ExternalLinkage, node.name, module.get());
	else
		fn = llvm::Function::Create(fnType, llvm::Function::PrivateLinkage, node.name, module.get());
	llvm::BasicBlock* block = llvm::BasicBlock::Create(module->getContext(), "entry", fn);
	builder->SetInsertPoint(block);
	std::cout << "Visiting block" << "\n";
	Visit(node.block, true);
	if(node.ty != Types::VOID)
	{
		llvm::Value* ret = valueStack.top();
		valueStack.pop();
		builder->CreateRet(ret);
	}
	else
		builder->CreateRetVoid();
	std::cout << rang::style::bold << rang::fg::green << "info: " << rang::style::reset << "verifying function " << node.name << "\n";
	llvm::verifyFunction(*fn);
}

void Visitor::NodeVisit(ArgNode &node)
{

}

void Visitor::NodeVisit(ArgsNode &node)
{

}

void Visitor::NodeVisit(BlockNode &node)
{
	std::cout << "Bless?" << "\n";
	for(ASTNode* i : node.stmts)
	{
		std::cout << "Visiting stmt" << "\n";
		std::cout << i << "\n"; 
		Visit(i, true);
	}	
}

void Visitor::NodeVisit(VarNode &node)
{

}

void Visitor::NodeVisit(ReturnNode &node)
{

}

