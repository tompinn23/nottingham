#include "Visitor.h"

#include <iostream>

#include "llvm/ADT/APInt.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Value.h"
#include "ast/AST.h"
#include "ast/ASTTypes.h"
using namespace AST;
using namespace Ni;

Visitor::Visitor(Module* module_arg) : module(std::unique_ptr<Module> (module_arg)),
	builder(std::unique_ptr<IRBuilder<> >(new IRBuilder<>(module->getContext())))
{

}

ASTNode* Ni::Visitor::Visit(ASTNode *node, bool visit)
{
	if(visit)
		if(node != NULL)
			return node->accept(*this);
		else
			std::cout << "Error node is null" << std::endl;
	//processedNodes.push_back(node);
	return node;
}

Visitor::~Visitor()
{
	for(ASTNode* i : processedNodes)
	{
		delete i;
	}
}

void Visitor::NodeVisit(IntNode &node)
{
	std::cout << "WOO IT WORKS" << std::endl;
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
	*this->Visit(node.val, true);
	llvm::Value* initValue = valueStack.top();
	valueStack.pop();
	if(node.global)
	{
		if(node.val->GetType() == NodeType::IntNode)
		{
			module->getOrInsertGlobal(node.varName, builder->getInt64Ty());
			llvm::GlobalVariable* glob = module->getGlobalVariable(node.varName);
			glob->setLinkage(llvm::GlobalValue::CommonLinkage);
			glob->setAlignment(4);
			glob->setInitializer(llvm::dyn_cast<llvm::ConstantInt>(initValue));
		}
		if(node.val->GetType() == NodeType::DoubleNode)
        {
            module->getOrInsertGlobal(node.varName, builder->getDoubleTy());
            llvm::GlobalVariable* glob = module->getGlobalVariable(node.varName);
            glob->setLinkage(llvm::GlobalValue::CommonLinkage);
            glob->setAlignment(4);
            glob->setInitializer(llvm::dyn_cast<llvm::ConstantFP>(initValue));
        }
		if(node.val->GetType() == NodeType::BoolNode)
        {
            module->getOrInsertGlobal(node.varName, builder->getInt1Ty());
            llvm::GlobalVariable* glob = module->getGlobalVariable(node.varName);
            glob->setLinkage(llvm::GlobalValue::CommonLinkage);
            glob->setAlignment(4);
            glob->setInitializer(llvm::dyn_cast<llvm::ConstantInt>(initValue));
        }
		if(node.val->GetType() == NodeType::StringNode)
        {
			llvm::ConstantDataArray* data = llvm::dyn_cast<llvm::ConstantDataArray>(initValue);
            module->getOrInsertGlobal(node.varName, data->getType());
            llvm::GlobalVariable* glob = module->getGlobalVariable(node.varName);
            glob->setLinkage(llvm::GlobalValue::CommonLinkage);
            glob->setAlignment(4);
            glob->setInitializer(llvm::dyn_cast<llvm::ConstantDataArray>(initValue));
        }
	}
	std::cout << "YAYA" << std::endl;
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
