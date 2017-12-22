add_library(nottsAST STATIC Ast.cc AstDestructors.cc)
add_dependencies(nottsAST nottsCodegen)
target_link_libraries(nottsAST nottsCodegen)


