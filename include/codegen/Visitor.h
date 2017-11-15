#ifndef VISITOR_H
#define VISITOR_H
#include "ast/ASTBaseNode.h"

using namespace AST;

namespace Ni {
	class Visitor {
	public:
		Visitor();
		ASTNode* Visit(ASTNode *node, bool visit);
		ASTNode* LitIntVisit(ASTNode* node);
		ASTNode* LitDoubleVisit(ASTNode* node);
		ASTNode* LitStringVisit(ASTNode* node);
		ASTNode* LitBoolVisit(ASTNode* node);
		ASTNode* DeclarationVisit(ASTNode* node);
	};
}
#endif // !VISITOR_H
