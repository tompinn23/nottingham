%{
	#include <iostream>
	#include <cstdlib>
	#include "parsing/lexer.h"
	#include "parser.hh"
	#include "driver/driver.h"
	#include "location.hh"
	using namespace std;
	#define YY_USER_ACTION driver.setLine(yylineno); \
		driver.setColumn(driver.col + yyleng);
	#define yyterminate() return Ni::Parser::make_EOF();

%}

%option nodefault
%option noyywrap
%option c++
%option yyclass="Lexer"
%option yylineno
%option prefix="Ni_"

nums [0-9]+
ident [_a-zA-Z][_a-zA-Z0-9]*
string  \"[^\n"]+\"

%%


[ \n\t\r] { }

def { return Ni::Parser::make_DEF(Ni::location(driver.filename, driver.line, driver.col)); }
return { return Ni::Parser::make_RETURN(Ni::location(driver.filename, driver.line, driver.col)); }
class {return Ni::Parser::make_CLASS(Ni::location(driver.filename, driver.line, driver.col)); }
pub { return Ni::Parser::make_PUB(Ni::location(driver.filename, driver.line, driver.col)); }
use { return Ni::Parser::make_USE(Ni::location(driver.filename, driver.line, driver.col)); }
self { return Ni::Parser::make_SELF(Ni::location(driver.filename, driver.line, driver.col)); }
if { return Ni::Parser::make_IF(Ni::location(driver.filename, driver.line, driver.col)); }
else { return Ni::Parser::make_ELSE(Ni::location(driver.filename, driver.line, driver.col)); }
elif { return Ni::Parser::make_ELIF(Ni::location(driver.filename, driver.line, driver.col)); }
switch { return Ni::Parser::make_SWITCH(Ni::location(driver.filename, driver.line, driver.col)); }
case { return Ni::Parser::make_CASE(Ni::location(driver.filename, driver.line, driver.col)); }
interface { return Ni::Parser::make_INTERFACE(Ni::location(driver.filename, driver.line, driver.col)); }
override { return Ni::Parser::make_OVERRIDE(Ni::location(driver.filename, driver.line, driver.col)); }
extends { return Ni::Parser::make_EXTENDS(Ni::location(driver.filename, driver.line, driver.col)); }
implements { return Ni::Parser::make_IMPLEMENTS(Ni::location(driver.filename, driver.line, driver.col)); }

type { return Ni::Parser::make_TYPE(Ni::location(driver.filename, driver.line, driver.col)); }

; { return Ni::Parser::make_END_STATEMENT(Ni::location(driver.filename, driver.line, driver.col)); }

true { return Ni::Parser::make_BOOL(true, Ni::location(driver.filename, driver.line, driver.col)); }

false { return Ni::Parser::make_BOOL(false, Ni::location(driver.filename, driver.line, driver.col)); }

\(    { return Ni::Parser::make_LEFTPAR(Ni::location(driver.filename, driver.line, driver.col)); }
\)    { return Ni::Parser::make_RIGHTPAR(Ni::location(driver.filename, driver.line, driver.col)); }
\{    { return Ni::Parser::make_LEFTBRACE(Ni::location(driver.filename, driver.line, driver.col)); }
\}    { return Ni::Parser::make_RIGHTBRACE(Ni::location(driver.filename, driver.line, driver.col)); }


-     { return Ni::Parser::make_MINUS(Ni::location(driver.filename, driver.line, driver.col)); }
-=    { return Ni::Parser::make_MINUSEQ(Ni::location(driver.filename, driver.line, driver.col)); }
\+    { return Ni::Parser::make_PLUS(Ni::location(driver.filename, driver.line, driver.col)); }
\+=   { return Ni::Parser::make_PLUSEQ(Ni::location(driver.filename, driver.line, driver.col)); }
\*    { return Ni::Parser::make_MUL(Ni::location(driver.filename, driver.line, driver.col)); }
\*=   { return Ni::Parser::make_MULEQ(Ni::location(driver.filename, driver.line, driver.col)); }
\/    { return Ni::Parser::make_DIV(Ni::location(driver.filename, driver.line, driver.col)); }
\/=   { return Ni::Parser::make_DIVEQ(Ni::location(driver.filename, driver.line, driver.col)); }

==    { return Ni::Parser::make_EQEQ(Ni::location(driver.filename, driver.line, driver.col)); }
=     { return Ni::Parser::make_EQ(Ni::location(driver.filename, driver.line, driver.col)); }
\!=   { return Ni::Parser::make_NE(Ni::location(driver.filename, driver.line, driver.col)); }
\!    { return Ni::Parser::make_NOT(Ni::location(driver.filename, driver.line, driver.col)); }
\<=   { return Ni::Parser::make_LE(Ni::location(driver.filename, driver.line, driver.col)); }
\<    { return Ni::Parser::make_LT(Ni::location(driver.filename, driver.line, driver.col)); }
\>=   { return Ni::Parser::make_GE(Ni::location(driver.filename, driver.line, driver.col)); }
\> 	  { return Ni::Parser::make_GT(Ni::location(driver.filename, driver.line, driver.col)); }
&&    {return Ni::Parser::make_ANDAND(Ni::location(driver.filename, driver.line, driver.col)); }
&     { return Ni::Parser::make_AND(Ni::location(driver.filename, driver.line, driver.col)); }
\|\|  { return Ni::Parser::make_OROR(Ni::location(driver.filename, driver.line, driver.col)); }
\|    { return Ni::Parser::make_OR(Ni::location(driver.filename, driver.line, driver.col)); }

[0-9]+ { return Ni::Parser::make_INT(atol(yytext), Ni::location(driver.filename, driver.line, driver.col)); }

[0-9]+\.[0-9]* {
	return Ni::Parser::make_DOUBLE(atof(yytext), Ni::location(driver.filename, driver.line, driver.col));
}

{ident} {
	return Ni::Parser::make_IDENTIFIER(yytext, Ni::location(driver.filename, driver.line, driver.col)) ;
}

{string} { return Ni::Parser::make_STRING(yytext, Ni::location(driver.filename, driver.line, driver.col)); }

. { cout << "Couldn't lex: " << yytext << endl; }

<<EOF>> { return Ni::Parser::make_EOF(Ni::location(driver.filename, driver.line, driver.col)); }

%%

