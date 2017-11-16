#ifndef AST_H
#define AST_H
#include <string>
#include <cstdarg>

#include "ASTBaseNode.h"
#include "ASTTypes.h"


namespace AST
{

enum Types
{
	INT,
	DOUBLE,
	BOOL,
	STRING,
};

Types StringToType(std::string str);


class DeclarationNode : public ASTNode {
public:
	DeclarationNode(Types ty, std::string name, ASTNode *v);
	ASTNode* GetValue();
	ASTNode* accept(Ni::Visitor &visitor) { return visitor.DeclarationVisit(this); }
private:
	std::string varName;
	Types varType;
	ASTNode *val;
};

};

#endif // !AST_H
