#include "codegen/Visitor.h"
#include "llvm/ADT/APInt.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Value.h"

Ni::Visitor::Visitor(Module* module_arg) : module(std::unique_ptr<Module> (module_arg)),
	builder(std::unique_ptr<IRBuilder<> >(new IRBuilder<>(module->getContext())))
{

}

ASTNode* Ni::Visitor::Visit(ASTNode *node, bool visit)
{
	if(visit)
		return node->accept(*this);
	return node;
}

ASTNode* Ni::Visitor::LitIntVisit(ASTNode* node)
{
	IntNode* intnode = dynamic_cast<IntNode*>(node);
	valueStack.push(llvm::ConstantInt::get(llvm::Type::getInt64Ty(module->getContext()), intnode->value, true));
	return node;
}

ASTNode* Ni::Visitor::LitDoubleVisit(ASTNode* node)
{
	DoubleNode* dub = dynamic_cast<DoubleNode*>(node);
	valueStack.push(llvm::ConstantFP::get(llvm::Type::getDoubleTy(module->getContext()), dub->value));
	return node;
}

ASTNode* Ni::Visitor::LitStringVisit(ASTNode* node)
{
	return node;
}

ASTNode* Ni::Visitor::LitBoolVisit(ASTNode* node)
{
	return node;
}

ASTNode* Ni::Visitor::DeclarationVisit(ASTNode* node)
{

}
