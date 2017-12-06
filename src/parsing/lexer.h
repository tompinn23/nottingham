#ifndef LEXER_H
#define LEXER_H


#if ! defined(yyFlexLexerOnce)
#undef yyFlexLexer
#define yyFlexLexer Ni_FlexLexer
#include <FlexLexer.h>
#endif


#undef YY_DECL
#define YY_DECL Ni::Parser::symbol_type Ni::Lexer::get_next_token()

#include "parser.hh"

namespace Ni {

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
