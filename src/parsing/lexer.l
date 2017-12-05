%{
	#include <iostream>
	#include <cstdlib>
	#include "parsing/lexer.h"
	#include "parser.hh"
	#include "driver/driver.h"
	#include "location.hh"
	using namespace std;
	#define YY_USER_ACTION driver.setLine(yylineno); \
		driver.setColumn(yyleng);
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

def { return Ni::Parser::make_DEF(Ni::location(driver.location())); }
return { return Ni::Parser::make_RETURN(Ni::location(driver.location()); }
class {return Ni::Parser::make_CLASS(Ni::location(driver.location()); }
pub { return Ni::Parser::make_PUB(Ni::location(driver.location()); }
use { return Ni::Parser::make_USE(Ni::location(driver.location()); }
self { return Ni::Parser::make_SELF(Ni::location(driver.location()); }
if { return Ni::Parser::make_IF(Ni::location(driver.location()); }
else { return Ni::Parser::make_ELSE(Ni::location(driver.location()); }
elif { return Ni::Parser::make_ELIF(Ni::location(driver.location()); }
switch { return Ni::Parser::make_SWITCH(Ni::location(driver.location()); }
case { return Ni::Parser::make_CASE(Ni::location(driver.location()); }
interface { return Ni::Parser::make_INTERFACE(Ni::location(driver.location()); }
override { return Ni::Parser::make_OVERRIDE(Ni::location(driver.location()); }
extends { return Ni::Parser::make_EXTENDS(Ni::location(driver.location()); }
implements { return Ni::Parser::make_IMPLEMENTS(Ni::location(driver.location()); }

type { return Ni::Parser::make_TYPE(Ni::location(driver.location()); }

; { return Ni::Parser::make_END_STATEMENT(Ni::location(driver.location()); }

true { return Ni::Parser::make_BOOL(true); }

false { return Ni::Parser::make_BOOL(false); }

\(    { return Ni::Parser::make_LEFTPAR(Ni::location(driver.location()); }
\)    { return Ni::Parser::make_RIGHTPAR(Ni::location(driver.location()); }
\{    { return Ni::Parser::make_LEFTBRACE(Ni::location(driver.location()); }
\}    { return Ni::Parser::make_RIGHTBRACE(Ni::location(driver.location()); }


-     { return Ni::Parser::make_MINUS(Ni::location(driver.location()); }
-=    { return Ni::Parser::make_MINUSEQ(Ni::location(driver.location()); }
\+    { return Ni::Parser::make_PLUS(Ni::location(driver.location()); }
\+=   { return Ni::Parser::make_PLUSEQ(Ni::location(driver.location()); }
\*    { return Ni::Parser::make_MUL(Ni::location(driver.location()); }
\*=   { return Ni::Parser::make_MULEQ(Ni::location(driver.location()); }
\/    { return Ni::Parser::make_DIV(Ni::location(driver.location()); }
\/=   { return Ni::Parser::make_DIVEQ(Ni::location(driver.location()); }

==    { return Ni::Parser::make_EQEQ(Ni::location(driver.location()); }
=     { return Ni::Parser::make_EQ(Ni::location(driver.location()); }
\!=   { return Ni::Parser::make_NE(Ni::location(driver.location()); }
\!    { return Ni::Parser::make_NOT(Ni::location(driver.location()); }
\<=   { return Ni::Parser::make_LE(Ni::location(driver.location()); }
\<    { return Ni::Parser::make_LT(Ni::location(driver.location()); }
\>=   { return Ni::Parser::make_GE(Ni::location(driver.location()); }
\> 	  { return Ni::Parser::make_GT(Ni::location(driver.location()); }
&&    {return Ni::Parser::make_ANDAND(Ni::location(driver.location()); }
&     { return Ni::Parser::make_AND(Ni::location(driver.location()); }
\|\|  { return Ni::Parser::make_OROR(Ni::location(driver.location()); }
\|    { return Ni::Parser::make_OR(Ni::location(driver.location()); }

[0-9]+ { return Ni::Parser::make_INT(atol(yytext), Ni::location(driver.location()); }

[0-9]+\.[0-9]* {
	return Ni::Parser::make_DOUBLE(atof(yytext), Ni::location(driver.location());
}

{ident} {
	return Ni::Parser::make_IDENTIFIER(std::string(yytext), Ni::location(driver.location()) ;
}

{string} { return Ni::Parser::make_STRING(std::string(yytext), Ni::location(driver.location()); }

. { cout << "Couldn't lex: " << yytext << endl; }

<<EOF>> { return Ni::Parser::make_EOF(Ni::location(driver.location()); }

%%

