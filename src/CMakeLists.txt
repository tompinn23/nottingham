project (NILANG VERSION 0.1.0)

set(NILANG_MAIN_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src CACHE STRING "The top level include directory")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LLVM_BUILD_TOOLS false CACHE BOOL "")
set(LLVM_BUILD_TESTS false CACHE BOOL "")
set(LLVM_INCLUDE_TESTS false CACHE BOOL "")
set(LLVM_BUILD_EXAMPLES false CACHE BOOL "")
set(LLVM_INCLUDE_EXAMPLES false CACHE BOOL "")
set(LLVM_TARGETS_TO_BUILD "X86" CACHE STRING "")

option(VENDOR_LIBS "Decide whether to use libs from vendor or not" false)

if(NOT VENDOR_LIBS)
add_subdirectory(llvm)

set(LLVM_DIR ${CMAKE_SOURCE_DIR}/build/src/llvm/lib/cmake/llvm)
message(${LLVM_DIR})
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

else()

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

endif()


include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


message(${LLVM_INCLUDE_DIRS})



IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
ENDIF()
include_directories(${NILANG_MAIN_INCLUDE_DIR} ${LLVM_INCLUDE_DIR} ${BISON_Parser_OUTPUT_HEADER} ${CMAKE_SOURCE_DIR}/src/parsing)
add_subdirectory(parsing)
add_subdirectory(ast)
add_subdirectory(codegen)
add_subdirectory(driver)

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()
