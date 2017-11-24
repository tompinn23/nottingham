add_library(NilangAST STATIC AST.cc)
add_dependencies(NilangAST NilangCodegen)
target_link_libraries(NilangAST NilangCodegen)


