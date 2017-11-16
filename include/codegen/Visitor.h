#ifndef VISITOR_H
#define VISITOR_H
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/Value.h"
#include <stack>

namespace AST
{
	class ASTNode;
}
using namespace AST;
using ::llvm::Module;
using ::llvm::IRBuilder;

namespace Ni {
	class Visitor {
	public:
		Visitor(Module* module);
		ASTNode* Visit(ASTNode *node, bool visit);
		ASTNode* LitIntVisit(ASTNode* node);
		ASTNode* LitDoubleVisit(ASTNode* node);
		ASTNode* LitStringVisit(ASTNode* node);
		ASTNode* LitBoolVisit(ASTNode* node);
		ASTNode* DeclarationVisit(ASTNode* node);
	private:
		std::unique_ptr<Module> module;
		std::unique_ptr<IRBuilder<> > builder;
		std::stack<llvm::Value*> valueStack;
	};
}
#endif // !VISITOR_H
