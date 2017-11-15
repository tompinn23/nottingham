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


