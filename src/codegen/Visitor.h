#ifndef VISITOR_H
#define VISITOR_H
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/Value.h"

#include <stack>

namespace AST{
	class ASTNode;
	class IntNode;
	class DoubleNode;
	class StringNode;
	class BoolNode;
	class DeclarationNode;
}

using namespace AST;
using ::llvm::Module;
using ::llvm::IRBuilder;

namespace Ni {

	class Visitor {
	public:
		Visitor(Module* module);
		ASTNode* Visit(ASTNode *node, bool visit);
		
		void NodeVisit(IntNode &node);
		void NodeVisit(DoubleNode &node);
		void NodeVisit(StringNode &node);
		void NodeVisit(BoolNode  &node);
		void NodeVisit(DeclarationNode &node);
	private:
		std::unique_ptr<Module> module;
		std::unique_ptr<IRBuilder<> > builder;
		std::stack<llvm::Value*> valueStack;
	};
}
#endif // !VISITOR_H
