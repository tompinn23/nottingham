#ifndef  AST_BASE_NODE_H
#define AST_BASE_NODE_H

namespace Ni {
	class Visitor;
}
namespace AST {
	enum class NodeType
	{
	    AstNode,
		IntNode,
	    BoolNode,
		StringNode,
	    DoubleNode,
	    DeclarationNode,
		BinOpNode,
	};
	class ASTNode {
	public:
		virtual ASTNode* accept(Ni::Visitor &visitor) = 0;
		virtual NodeType GetType() { return NodeType::AstNode; }
		virtual ~ASTNode() {}
	};
}

#endif // ! AST_BASE_NODE_H
