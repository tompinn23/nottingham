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
	return node;
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
	llvm::Value* initValue = valueStack.pop();
	*initValue->getType();
	std::cout << "YAYA" << std::endl;
}
