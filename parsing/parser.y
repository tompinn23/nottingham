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
#include "tokens.h"
#include "ast/AST.h"
using namespace std;


void yyerror(const char *s);

namespace Ni {
	class Lexer;
	class Driver;
}

%}

%code top
{
	#include <iostream>
	#include "lexer.h"
	#include "parser.h"

	static Ni::Parser::symbol_type yylex(Ni:Lexer &lexer {
		return lexer.get_next_token();
	}

	using namespace Ni;
}

%lex-param { Ni::Lexer &lexer }
%lex-param { Ni::Driver &driver }
%parse-param { Ni::Lexer &lexer }
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
%type <AST::ASTNode> item_dec
%type <AST::ASTNode> expr

%start program

%%

program
: item
;

item
: item_dec
;

item_dec
: ty IDENTIFIER '=' expr {$$ = AST::DeclarationNode($1, $2);}
;

ty
: %empty

expr: 
%empty
%%

void Ni::Parser::error(const std::string &message)
{
	cout << "Error: " << message << endl;

}
