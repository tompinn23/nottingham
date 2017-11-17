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

#include "ast/AST.h"
#include "codegen/Visitor.h"
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
%type <AST::ASTNode*> item_dec
%type <AST::ASTNode*> expr

%start program

%%

program
: item
;

item
: item_dec  { visitor.Visit($1, visit); }
| EOF
;

item_dec
: ty IDENTIFIER EQ expr {$$ = new AST::DeclarationNode($1, $2, $4);}
;

ty
: IDENTIFIER { $$ = AST::StringToType($1); }
;

expr
: INT {  $$ = new AST::IntNode($1); }
| DOUBLE { $$ = new AST::DoubleNode($1); }
| STRING { $$ = new AST::StringNode($1); }
| BOOL { $$ = new AST::BoolNode($1); }
;
%%

void Ni::Parser::error(const std::string &message)
{
	cout << "Error: " << message << endl;

}
