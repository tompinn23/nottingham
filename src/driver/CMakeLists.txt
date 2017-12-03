
add_executable(nilang main.cc driver.cc)
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
