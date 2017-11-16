#ifndef  AST_BASE_NODE_H
#define AST_BASE_NODE_H
#include "codegen/Visitor.h"
namespace Ni {
}
namespace AST {
	class ASTNode {
	public:
		virtual ASTNode* accept(Ni::Visitor &visitor) = 0;

	};
}

#endif // ! AST_BASE_NODE_H
