#include <iostream>

#include "ast/Ast.h"
using namespace AST;

DeclarationNode::~DeclarationNode()
{
    std::cout << val << "\n";
    //delete val;
}

BinOpNode::~BinOpNode()
{
    //delete lhs;
    //delete rhs;
}

FunctionNode::~FunctionNode()
{
    //delete args;
    //delete block;
}

ArgsNode::~ArgsNode()
{
    //2for(ArgNode* i : args)
    //{
        //delete i;
    //}
}

BlockNode::~BlockNode()
{
    //for(ASTNode* i : stmts)
    //{
        //delete i;
    //}
}

ReturnNode::~ReturnNode()
{
    //delete retVal;
}


