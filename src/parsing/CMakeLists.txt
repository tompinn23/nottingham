find_package(BISON)
find_package(FLEX)

BISON_TARGET(Parser parser.y ${CMAKE_CURRENT_SOURCE_DIR}/parser.cc)
FLEX_TARGET(Lexer lexer.l ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cc)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

set(BISON_HEADER_DIR ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)
message(${BISON_Parser_OUTPUTS})

add_library(NilangParsing
	dummy.cc
	${BISON_Parser_OUTPUTS}
	${FLEX_Lexer_OUTPUTS}
	)
add_dependencies(NilangParsing NilangAST NilangCodegen)
target_link_libraries(NilangParsing NilangAST NilangCodegen)
