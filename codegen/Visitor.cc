#include "codegen/Visitor.h"


Ni::Visitor::Visitor()
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
	return node;
}

ASTNode* Ni::Visitor::LitDoubleVisit(ASTNode* node)
{
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
	return node;
}
