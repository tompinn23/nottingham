#ifndef AST_H
#define AST_H
#include <string>
#include <cstdarg>

#include "ASTBaseNode.h"
#include "ASTTypes.h"
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
	bool global = false;
	std::string varName;
	Types varType;
	ASTNode *val;
};

};

#endif // !AST_H
