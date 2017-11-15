
add_executable(nilang main.cc driver.cc)
add_dependencies(nilang NilangAST NilangCodegen NilangParsing)
llvm_map_components_to_libnames(llvm_libs all)
target_link_libraries(nilang ${llvm_libs} NilangAST NilangCodegen NilangParsing)
