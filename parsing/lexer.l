%{
#include <iostream>
#include <string>
#include "parser.hh"
using namespace std;

#define yyterminate() Ni::Parser::make_EOF()

%}

%option nodefault
%option noyywrap
%option c++
%option yyclass="Lexer"
%option outfile="lexer.cc"

nums [0-9]+
ident [a-zA-Z][a-zA-Z0-9]+
string  \"[^\n"]+\"


%%


[ \n\t\r] { }

def { make_DEF(); }
return { make_RETURN(); }
class {make_CLASS(); }
pub { make_PUB(); }
use { make_USE(); }
self { make_SELF(); }
if { make_IF(); }
else { make_ELSE(); }
elif { make_ELIF(); }
switch { make_SWITCH(); }
case { make_CASE(); }
interface { make_INTERFACE(); }
override { make_OVERRIDE(); }
extends { make_EXTENDS(); }
implements { make_IMPLEMENTS(); }

type { make_TYPE(); }

; { make_END_STATEMENT(); }

true { make_BOOL(true); }

false { make_BOOL(false); }

\(    { make_LEFTPAR(); }
\)    { make_RIGHTPAR(); }
\{    { make_LEFTBRACE(); }
\}    { make_RIGHTBRACE(); }


-     { make_MINUS(); }
-=    { make_MINUSEQ(); }
\+    { make_PLUS(); }
\+=   { make_PLUSEQ(); }
\*    { make_MUL(); }
\*=   { make_MULEQ(); }
\/    { make_DIV(); }
\/=   { make_DIVEQ(); }

==    { make_EQEQ(); }
=     { make_EQ(); }
\!=   { make_NE(); }
\!    { make_NOT(); }
\<=   { make_LE(); }
\<    { make_LT(); }
\>=   { make_GE(); }
\> 	  { make_GT(); }
&&    {make_ANDAND(); }
&     { make_AND(); }
\|\|  { make_OROR(); }
\|    { make_OR(); }

{nums} { make_INT(atol(yytext)); }

[0-9]+\.[0-9]* {
	make_DOUBLE(atof(yytext);
}

{ident} {
	make_IDENTIFIER(std::string(yytext));
}

{string} { make_STRING(std::string(yytext)); }



<<EOF>> { make_EOF(); }

%%

