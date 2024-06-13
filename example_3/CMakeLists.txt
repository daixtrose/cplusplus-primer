cmake_minimum_required(VERSION 3.29)

project(example_3 VERSION 1.0.0 LANGUAGES CXX)

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
    SOURCE_DIR ../library_1
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

# Package-specific Settings
install(TARGETS ${PROJECT_NAME} library_1)

# These are project-specific
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "Daixtrose Engineering")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An example project")
set(CPACK_PACKAGE_CONTACT "daixtrose.engineering@gmx.de")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Markus Werle")

# These lines tend to be the same for every project
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set(CPACK_VERBATIM_VARIABLES TRUE)

# Configure what kind of packages will be created based on the platform
if(WIN32)
    set(CPACK_GENERATOR ZIP WIX)
elseif(APPLE)
    set(CPACK_GENERATOR TGZ productbuild)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CPACK_GENERATOR TGZ RPM DEB)
else()
    set(CPACK_GENERATOR TGZ)
endif()

# This is what writes out the input file for CPack
include(CPack)
