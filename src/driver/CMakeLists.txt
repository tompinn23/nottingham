# Get the current working branch
execute_process(
  COMMAND git rev-parse --abbrev-ref HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_BRANCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the latest abbreviated commit hash of the working branch
execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_COMMIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
    ${CMAKE_BINARY_DIR}/version.h
)


add_executable(nilang main.cc driver.cc)
include_directories(${CMAKE_BINARY_DIR})
add_dependencies(nilang NilangAST NilangCodegen NilangParsing)
llvm_map_components_to_libnames(llvm_libs
asmparser 
asmprinter 
binaryformat 
bitreader 
bitwriter 
codegen 
core 
coroutines 
coverage 
debuginfocodeview 
debuginfodwarf 
debuginfomsf 
debuginfopdb
demangle 
dlltooldriver 
globalisel 
instcombine 
instrumentation 
interpreter 
ipo 
irreader 
libdriver 
lineeditor 
linker 
lto 
native 
nativecodegen 
objcarcopts 
object 
objectyaml 
option 
passes 
profiledata 
runtimedyld 
scalaropts 
selectiondag 
support 
symbolize 
tablegen 
target 
transformutils 
vectorize 

x86asmparser 
x86asmprinter 
x86codegen 
x86desc 
x86disassembler 
x86info 
x86utils
)
target_link_libraries(nilang ${llvm_libs} NilangAST NilangCodegen NilangParsing)
