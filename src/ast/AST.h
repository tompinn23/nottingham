#ifndef AST_H
#define AST_H
#include <string>
#include <cstdarg>

#include "ASTBaseNode.h"
#include "codegen/Visitor.h"


namespace AST
{

enum class Types
{
	INT,
	DOUBLE,
	BOOL,
	STRING,
	VOID,
	UserDefined,
};

Types StringToType(std::string str);



class DeclarationNode : public ASTNode {
public:
	DeclarationNode(Types ty, std::string name, ASTNode *v);
	~DeclarationNode() { delete val; }
	ASTNode* GetValue();
	ASTNode* accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
	NodeType GetType() { return NodeType::DeclarationNode; }
	bool global = false;
	std::string varName;
	Types varType;
	ASTNode* val;
};

class BinOpNode : public ASTNode {
public:
	BinOpNode(std::string op_arg, ASTNode* lhs_arg,  ASTNode* rhs_arg) : op(op_arg), lhs(lhs_arg), rhs(rhs_arg) {}
	~BinOpNode() { delete lhs;  delete rhs; }
	ASTNode* accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
	NodeType GetType() { return NodeType::BinOpNode; }
	std::string op;
	ASTNode* lhs;
	ASTNode* rhs;
};
class FunctionNode : public ASTNode {
public:
	//TODO: Args?
	FunctionNode(bool pub, std::string name, AST::Types ty, ASTNode* args, ASTNode* block)
	: pub(pub), name(name), ty(ty), args(args), block(block) {}
	ASTNode* accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
	NodeType GetType() { return NodeType::FunctionNode; }

	bool pub;
	std::string name;
	AST::Types ty;
	ArgsNode* args;
	BlockNode* block;
};

class ArgNode : public ASTNode {
public:
    ArgNode(Types ty_arg, std::string name_arg) : ty(ty_arg), name(name_arg) {}
    ASTNode * accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
    NodeType GetType() { return NodeType::ArgNode; }
	Types ty;
	std::string name;
};

class ArgsNode : public ASTNode {
public:
	ArgsNode(ArgNode* init) { args.push_back(init); }
	ASTNode* accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
	NodeType GetType() { return NodeType::ArgsNode; }
	void Extend(ArgNode* node) { args.push_back(node); }
	std::vector<ArgNode*> args;
};

class BlockNode : public ASTNode {
public:
	BlockNode(ASTNode* stmt) {};
	ASTNode* accept(Ni::Visitor &visitor) { return this; }
	NodeType GetType() { return NodeType::BlockNode; }
	void Extend(ASTNode* node) {}
	std::vector<ASTNode*> stmts;
};

class EndBlockNode : public ASTNode {
public:
	EndBlockNode() {};
	ASTNode* accept(Ni::Visitor &visitor) { return this; }
	NodeType GetType() { return NodeType::EndBlockNode; }
};

class ReturnNode : public ASTNode {
public:
	ReturnNode(ASTNode* val) : retVal(val) {}
	ASTNode* accept(Ni::Visitor &visitor) {visitor.NodeVisit(*this); return  this;}
	NodeType GetType() { return NodeType::ReturnNode; }

	ASTNode* retVal;
};

class VarNode : public ASTNode {
public:
	VarNode(std::string name) : name(name) {}
	ASTNode* accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
	NodeType GetType() { return NodeType::VarNode; }
	
	std::string name;
};

};

#endif // !AST_H
