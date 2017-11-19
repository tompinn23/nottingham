#ifndef  AST_BASE_NODE_H
#define AST_BASE_NODE_H

namespace Ni {
	class Visitor;
}
namespace AST {
	class ASTNode {
	public:
		virtual ASTNode* accept(Ni::Visitor &visitor) = 0;
		virtual ~ASTNode() {}
	};
}

#endif // ! AST_BASE_NODE_H
