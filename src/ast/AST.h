#ifndef AST_H
#define AST_H
#include <string>
#include <cstdarg>

#include "ASTBaseNode.h"
#include "codegen/Visitor.h"


namespace AST
{

enum Types
{
	INT,
	DOUBLE,
	BOOL,
	STRING,
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

};

#endif // !AST_H
