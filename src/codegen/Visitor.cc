#include "codegen/Visitor.h"

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
		return node->accept(*this);
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
	*this->Visit(node.GetValue(), true);
	llvm::Value* initValue = valueStack.top();
	valueStack.pop();
	if(node.global)
	{
		llvm::Type* initType = initValue->getType();
		if(initType->isArrayTy())
		{
			llvm::ConstantArray* val = llvm::dyn_cast<llvm::ConstantArray>(initValue);
			module->getOrInsertGlobal(node.varName, val->getType());
		} 
		if(initType->isDoubleTy())
			module->getOrInsertGlobal(node.varName, builder->getDoubleTy());
		if(initType->isIntegerTy())
			module->getOrInsertGlobal(node.varName, builder->getInt64Ty());

		llvm::GlobalVariable* glob = module->getGlobalVariable(node.varName);
		glob->setLinkage(llvm::GlobalValue::CommonLinkage);
		glob->setAlignment(4);
		
		if(initType->isArrayTy())
			glob->setInitializer(llvm::dyn_cast<llvm::ConstantArray>(initValue));
		if(initType->isDoubleTy())
			glob->setInitializer(llvm::dyn_cast<llvm::ConstantFP>(initValue));
		if(initType->isIntegerTy())
			glob->setInitializer(llvm::dyn_cast<llvm::ConstantInt>(initValue));

	
	}
	std::cout << "YAYA" << std::endl;
}
