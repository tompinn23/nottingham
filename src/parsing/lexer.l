%{
	#include <iostream>
	#include <cstdlib>
	#include "parsing/lexer.h"
	#include "parser.hh"

	using namespace std;

	#define yyterminate() return Ni::Parser::make_EOF();

%}

%option nodefault
%option noyywrap
%option c++
%option yyclass="Lexer"
%option prefix="Ni_"

nums [0-9]+
ident [_a-zA-Z][_a-zA-Z0-9]*
string  \"[^\n"]+\"

%%


[ \n\t\r] { }

def { return Ni::Parser::make_DEF(); }
return { return Ni::Parser::make_RETURN(); }
class {return Ni::Parser::make_CLASS(); }
pub { return Ni::Parser::make_PUB(); }
use { return Ni::Parser::make_USE(); }
self { return Ni::Parser::make_SELF(); }
if { return Ni::Parser::make_IF(); }
else { return Ni::Parser::make_ELSE(); }
elif { return Ni::Parser::make_ELIF(); }
switch { return Ni::Parser::make_SWITCH(); }
case { return Ni::Parser::make_CASE(); }
interface { return Ni::Parser::make_INTERFACE(); }
override { return Ni::Parser::make_OVERRIDE(); }
extends { return Ni::Parser::make_EXTENDS(); }
implements { return Ni::Parser::make_IMPLEMENTS(); }

type { return Ni::Parser::make_TYPE(); }

; { return Ni::Parser::make_END_STATEMENT(); }

true { return Ni::Parser::make_BOOL(true); }

false { return Ni::Parser::make_BOOL(false); }

\(    { return Ni::Parser::make_LEFTPAR(); }
\)    { return Ni::Parser::make_RIGHTPAR(); }
\{    { return Ni::Parser::make_LEFTBRACE(); }
\}    { return Ni::Parser::make_RIGHTBRACE(); }


-     { return Ni::Parser::make_MINUS(); }
-=    { return Ni::Parser::make_MINUSEQ(); }
\+    { return Ni::Parser::make_PLUS(); }
\+=   { return Ni::Parser::make_PLUSEQ(); }
\*    { return Ni::Parser::make_MUL(); }
\*=   { return Ni::Parser::make_MULEQ(); }
\/    { return Ni::Parser::make_DIV(); }
\/=   { return Ni::Parser::make_DIVEQ(); }

==    { return Ni::Parser::make_EQEQ(); }
=     { return Ni::Parser::make_EQ(); }
\!=   { return Ni::Parser::make_NE(); }
\!    { return Ni::Parser::make_NOT(); }
\<=   { return Ni::Parser::make_LE(); }
\<    { return Ni::Parser::make_LT(); }
\>=   { return Ni::Parser::make_GE(); }
\> 	  { return Ni::Parser::make_GT(); }
&&    {return Ni::Parser::make_ANDAND(); }
&     { return Ni::Parser::make_AND(); }
\|\|  { return Ni::Parser::make_OROR(); }
\|    { return Ni::Parser::make_OR(); }

[0-9]+ { return Ni::Parser::make_INT(atol(yytext)); }

[0-9]+\.[0-9]* {
	return Ni::Parser::make_DOUBLE(atof(yytext));
}

{ident} {
	return Ni::Parser::make_IDENTIFIER(std::string(yytext));
}

{string} { return Ni::Parser::make_STRING(std::string(yytext)); }

. { cout << "Couldn't lex: " << yytext << endl; }

<<EOF>> { return Ni::Parser::make_EOF(); }

%%

