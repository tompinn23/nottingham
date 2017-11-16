#ifndef  AST_TYPES_H
#define AST_TYPES_H

#include "ASTBaseNode.h"
#include <string>
using namespace Ni;
namespace AST {
	class IntNode : public ASTNode {
	public:
		IntNode(long v) : value(v) {}
		long value;
		ASTNode* accept(Visitor &visitor) { return visitor.LitIntVisit(this); }
	};

	class DoubleNode : public ASTNode {
	public:
		DoubleNode(double v) : value(v) {}
		double value;
		ASTNode* accept(Visitor &visitor) { return visitor.LitDoubleVisit(this); }
	};
	class StringNode : public ASTNode {
	public:
		StringNode(std::string v) : value(v) {}
		std::string value;
		ASTNode* accept(Visitor &visitor) { return visitor.LitStringVisit(this); }
	};
	class BoolNode: public ASTNode {
	public:
		BoolNode(bool v) : value(v) {}
		bool value;
		ASTNode* accept(Visitor &visitor) { return visitor.LitBoolVisit(this); }
	};
}


#endif // ! AST_TYPES_H
