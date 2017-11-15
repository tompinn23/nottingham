#include "ast/AST.h"

using namespace AST;

AST::DeclarationNode::DeclarationNode(Types ty, std::string name, ASTNode *v)
{
	varType = ty;
	varName = name;
	val = v;
}

ASTNode* AST::DeclarationNode::GetValue()
{
	return val;
}
