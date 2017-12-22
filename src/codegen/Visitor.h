#ifndef VISITOR_H
#define VISITOR_H
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/Value.h"

#include <stack>
#include <vector>

namespace AST{
	class ASTNode;
	class IntNode;
	class DoubleNode;
	class StringNode;
	class BoolNode;
	class DeclarationNode;
	class BinOpNode;
	class FunctionNode;
	class BlockNode;
	class EndBlockNode;
	class ArgNode;
	class ArgsNode;
	class ReturnNode;
	class VarNode;
}
using namespace AST;
using ::llvm::Module;
using ::llvm::IRBuilder;

namespace Ni {

	class Visitor {
	public:
		Visitor(Module* module);
		~Visitor();
		ASTNode* Visit(ASTNode *node, bool visit);
		
		void NodeVisit(IntNode &node);
		void NodeVisit(DoubleNode &node);
		void NodeVisit(StringNode &node);
		void NodeVisit(BoolNode  &node);
		void NodeVisit(DeclarationNode &node);
		void NodeVisit(BinOpNode &node);
		void NodeVisit(FunctionNode &node);
		void NodeVisit(ArgNode &node);
		void NodeVisit(ArgsNode &node);
		void NodeVisit(VarNode &node);
		void NodeVisit(ReturnNode &node);
		void NodeVisit(BlockNode &node);
		std::unique_ptr<Module> module;
		bool EnterContext();		
		bool LeaveContext();
	private:
		std::unique_ptr<IRBuilder<> > builder;
		std::stack<llvm::Value*> valueStack;
		std::vector<ASTNode*> processedNodes;
		std::vector<llvm::Value*>* ctx;
		std::stack<std::vector<llvm::Value*>*> contexts; 
	};
}
#endif //VISITOR_H
