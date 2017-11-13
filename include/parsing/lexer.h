#ifndef LEXER_H
#define LEXER_H

#include <FlexLexer.h>

#undef YY_DECL
#define YY_DECL Ni::Parser::symbol_type Ni::Scanner::get_next_token()

#include "parser.hh"

namespace Ni {

class Driver;

class Lexer : public yyFlexLexer {
public:
	Lexer(Driver &drive): driver(drive) {}
	virtual ~Lexer() {}
	virtual Ni::Parser::symbol_type get_next_token();
private:
	Driver &driver;
};	
	
}
#endif