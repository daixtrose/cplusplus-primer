cmake_minimum_required(VERSION 3.29)

project(example_4 VERSION 1.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

# See https://github.com/daixtrose/cmake_utilities for what else you can do with FetchContent
include(FetchContent)

# Quote from https://www.daixtrose.de/talk/saying-goodbye-to-dependency-hell.html#46
#
# FetchContent_Declare(some_name SOURCE_DIR /path/to/directory)
# does **not** fetch the content, but **refers** to it directly.
# This means that the debugger symbols will point to the original code.
# AFAICS this is the most efficient usage of hard disk space,
# since the code for every dependency is stored on disk exactly once.
FetchContent_Declare(
    library_1
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../library_1
)

FetchContent_MakeAvailable(library_1)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC

    # Here all the magic happens:
    # - The include paths are set accordingly
    # - The linker instructions are set accordingly
    # Hint: This requires sanity in the library's CMakeLists.txt
    demo::library_1
)

include(${CMAKE_CURRENT_LIST_DIR}/CMakeListsCPackConfiguration.txt)
