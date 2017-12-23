#ifndef AST_H
#define AST_H
#include <string>
#include <cstdarg>

#include "AstBase.h"
#include "codegen/Visitor.h"

/**
 * The AST namespace which contains the varying classes for the Abstract Syntax Tree 
 */
namespace AST
{

enum class Types
{
	INT,  /**< Integer Type */
	DOUBLE, /**< Double Type */
	BOOL, /**< Boolean Type */
	STRING, /**< String Type */
	VOID, /**< Void Type */
	UserDefined, /**< User Defined Type eg. Class */
};
/**
 * Converts a string to AST::Types 
 */
Types StringToType(std::string str);


/**
 * Declaration Node Class
 * 
 * Defines how variables declarations are stored
 */
class DeclarationNode : public ASTNode {
public:
	DeclarationNode(Types ty, std::string name, ASTNode *v);
	~DeclarationNode();
	ASTNode* GetValue();
	ASTNode* accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
	NodeType GetType() { return NodeType::DeclarationNode; }
	bool global = false;
	std::string varName;
	Types varType;
	ASTNode* val;
};

/**
 * Binary Operation Node Class
 * 
 * Define the binary operation node
 */
class BinOpNode : public ASTNode {
public:
	BinOpNode(std::string op_arg, ASTNode* lhs_arg,  ASTNode* rhs_arg) : op(op_arg), lhs(lhs_arg), rhs(rhs_arg) {}
	~BinOpNode();
	ASTNode* accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
	NodeType GetType() { return NodeType::BinOpNode; }
	std::string op;
	ASTNode* lhs;
	ASTNode* rhs;
};

/**
 * Function Node Class
 * 
 * Defines the node of a function
 */
class FunctionNode : public ASTNode {
public:
	//TODO: Args?
	FunctionNode(bool pub, std::string name, AST::Types ty, ArgsNode* args, BlockNode* block)
	: pub(pub), name(name), ty(ty), args(args), block(block) {}
	~FunctionNode();
	ASTNode* accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
	NodeType GetType() { return NodeType::FunctionNode; }

	bool pub;
	std::string name;
	AST::Types ty;
	ArgsNode* args;
	BlockNode* block;
};
/**
 * ArgNode Class
 * 
 * This class defines a single argument.
 */
class ArgNode : public ASTNode {
public:
    ArgNode(Types ty_arg, std::string name_arg) : ty(ty_arg), name(name_arg) {}
    ASTNode * accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
    NodeType GetType() { return NodeType::ArgNode; }
	Types ty;
	std::string name;
};

/**
 * ArgsNode Class
 * 
 * This class defines a list of arguments.
 */
class ArgsNode : public ASTNode {
public:
	ArgsNode(ArgNode* init) { args.push_back(init); }
	~ArgsNode();
	ASTNode* accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
	NodeType GetType() { return NodeType::ArgsNode; }
	void Extend(ArgNode* node) { args.push_back(node); }
	std::vector<ArgNode*> args;
};

/**
 * BlockNode Class
 * 
 * This class defines a block of statements
 */
class BlockNode : public ASTNode {
public:
	BlockNode(ASTNode* stmt) {stmts.push_back(stmt); };
	~BlockNode();
	ASTNode* accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
	NodeType GetType() { return NodeType::BlockNode; }
	void Extend(ASTNode* node) {stmts.push_back(node);}
	std::vector<ASTNode*> stmts;
};

/* 
class EndBlockNode : public ASTNode {
public:
	EndBlockNode() {};
	ASTNode* accept(Ni::Visitor &visitor) { return this; }
	NodeType GetType() { return NodeType::EndBlockNode; }
};
 */
/**
 * Return Class
 * 
 * This class defines a return instruction.
 */
class ReturnNode : public ASTNode {
public:
	ReturnNode(ASTNode* val) : retVal(val) {}
	~ReturnNode();
	ASTNode* accept(Ni::Visitor &visitor) {visitor.NodeVisit(*this); return  this;}
	NodeType GetType() { return NodeType::ReturnNode; }
	ASTNode* retVal;
};

/**
 * Var Class
 * 
 * This class defines a variable accessor.
 */
class VarNode : public ASTNode {
public:
	VarNode(std::string name) : name(name) {}
	ASTNode* accept(Ni::Visitor &visitor) { visitor.NodeVisit(*this); return this; }
	NodeType GetType() { return NodeType::VarNode; }
	
	std::string name;
};

};

#endif // !AST_H
