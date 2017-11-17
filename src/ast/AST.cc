#include "ast/AST.h"

using namespace AST;

AST::DeclarationNode::DeclarationNode(Types ty, std::string name, ASTNode *v)
{
	varType = ty;
	varName = name;
	val = v;
}

ASTNode* AST::DeclarationNode::GetValue()
{
	return val;
}

Types AST::StringToType(std::string str)
{
	if(str == "int")
		return Types::INT;
	if(str == "double")
		return Types::DOUBLE;
	if(str == "bool")
		return Types::BOOL;
	if(str == "string")
		return Types::STRING;
	return Types::UserDefined;
}
