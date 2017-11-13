find_package(BISON)
find_package(FLEX)

BISON_TARGET(Parser parser.y ${CMAKE_CURRENT_SOURCE_DIR}/parser.cc)
FLEX_TARGET(Lexer lexer.l ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cc)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

add_library(NilangParsing
	dummy.cc
	${BISON_Parser_TARGETS}
	${FLEX_Lexer_TARGETS}
	)
