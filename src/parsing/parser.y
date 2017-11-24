%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0"
%defines
%define parser_class_name { Parser }

%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define api.namespace { Ni }
%code requires
{
#include <iostream>
#include <string>

#include "codegen/Visitor.h"
#include "ast/AST.h"
#include "ast/ASTTypes.h"
using namespace std;


#ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

void yyerror(const char *s);

namespace Ni {
	class Lexer;
	class Driver;
}

}

%code top
{
	# ifndef YY_NULLPTR
	#  if defined __cplusplus && 201103L <= __cplusplus
	#   define YY_NULLPTR nullptr
	#  else
	#   define YY_NULLPTR 0
	#  endif
	# endif
	#include <iostream>
	#include "parsing/lexer.h"
	#include "parser.hh"
	static Ni::Parser::symbol_type yylex(Ni::Lexer &lexer, Ni::Driver &driver) {
		return lexer.get_next_token();
	}
	
	static bool visit = true;
	static AST::BlockNode* ext_blk(AST::BlockNode* node, AST::ASTNode* ext)
	{	
		node->Extend(ext);
		return node;
	}
	
	static AST::ArgsNode* ext_args(AST::ArgsNode* args, AST::ArgNode* arg)
	{
		args->Extend(arg);
		return args;
	}

	using namespace Ni;
}

%lex-param { Ni::Lexer &lexer }
%lex-param { Ni::Driver &driver }
%parse-param { Ni::Lexer &lexer }
%parse-param { Ni::Visitor &visitor }
%parse-param { Ni::Driver &driver }

%define parse.trace
%define parse.error verbose
%define api.token.prefix {TOKEN_}

// Keywords & Misc
%token DEF 
%token RETURN
%token CLASS
%token PUB
%token USE
%token SELF
%token IF
%token ELSE
%token ELIF
%token SWITCH
%token CASE
%token INTERFACE
%token OVERRIDE
%token EXTENDS
%token IMPLEMENTS

%token TYPE
%token END_STATEMENT

%token LEFTPAR
%token RIGHTPAR
%token LEFTBRACE
%token RIGHTBRACE

%token EOF 0
// Operators 
%token MINUS
%token MINUSEQ
%token PLUS
%token PLUSEQ
%token MUL
%token MULEQ
%token DIV
%token DIVEQ

%token EQEQ
%token EQ
%token NE
%token NOT
%token LE
%token LT
%token GE
%token GT
%token ANDAND
%token AND
%token OROR
%token OR



// Actual Data Types

%token <long> INT
%token <double> DOUBLE
%token <bool> BOOL
%token <std::string> IDENTIFIER
%token <std::string> STRING

%type <AST::Types> ty
%type <AST::DeclarationNode*> item_dec
%type <AST::FunctionNode*> fn
%type <AST::BlockNode*> block_items block
%type <AST::ASTNode*> expr lit litnum term factor block_item args
%type <AST:ReturnNode*> return
%type <AST::VarNode*> var
%start program

%%

program
: items
;

items
: item
| items item
| EOF
;
	

item
: item_dec  { $1->global = true; visitor.Visit($1, visit);}
| fn
;

item_dec
: ty IDENTIFIER EQ expr END_STATEMENT {$$ = new AST::DeclarationNode($1, $2, $4); std::cout << $4 << std::endl;}
;

ty
: IDENTIFIER { $$ = AST::StringToType($1); }
;

fn
: PUB DEF ty IDENTIFIER LEFTPAR args RIGHTPAR block { $$ = new AST::FunctionNode(true, $4, $3, $6, $8); }
| DEF ty IDENTIFIER LEFTPAR args RIGHTPAR block { $$ = new AST::FunctionNode(false, $3, $2, $5, $7); }
;

args
: arg { $$ = nullptr; } 
| %empty { $$ = nullptr; }
;

arg
: ty IDENTIFIER
;

block
: LEFTBRACE block_items { $$ = $2; };
;

block_items
: block_item { $$ = new AST::BlockNode($1); }
| block_items block_item { $$ = ext_blk($1, $2); }
| RIGHTBRACE { $$ = new AST::BlockNode(new AST::IntNode(10)); }
;

block_item
: item_dec { $$ = $1; } 
| return { $$ = $1; }
;

return
: RETURN expr END_STATEMENT { $$ = new ReturnNode($2); }
| RETURN var END_STATEMENT { $$ = new ReturnNode($2); }
;

var
: IDENTIFIER { $$ = new VarNode($1); }
;


expr
: expr PLUS term { $$ = new AST::BinOpNode("+", $1, $3); }
| expr MINUS term { $$ = new AST::BinOpNode("-", $1, $3); }
| term { $$ = $1; }
| lit { $$ = $1; }
;

term
: term MUL factor { $$ = new AST::BinOpNode("*", $1, $3); }
| term DIV factor { $$ = new AST::BinOpNode("/", $1, $3); }
| factor { $$ = $1; } 
;


factor
: LEFTPAR expr RIGHTPAR { $$ = $2; }
| MINUS factor { $$ = $2; }
| litnum { $$ = $1; } 
;

litnum
: INT { $$ = new AST::IntNode($1); std::cout << $$ << std::endl;}
| DOUBLE { $$ = new AST::DoubleNode($1); }
;



lit
: STRING 
{ 
	$1.erase(0, 1);
	$1.erase($1.size() -1);
	$$ = new AST::StringNode($1); 
}
| BOOL { $$ = new AST::BoolNode($1); }
;
%%

void Ni::Parser::error(const std::string &message)
{
	cout << "Error: " << message << endl;

}
