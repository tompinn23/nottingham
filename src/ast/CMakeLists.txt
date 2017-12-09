add_library(nottsAST STATIC AST.cc)
add_dependencies(nottsAST nottsCodegen)
target_link_libraries(nottsAST nottsCodegen)


