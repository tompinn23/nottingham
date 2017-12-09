
add_executable(notts main.cc driver.cc)
add_dependencies(notts nottsAST nottsCodegen nottsParsing)
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
target_link_libraries(notts ${llvm_libs} nottsAST nottsCodegen nottsParsing)
