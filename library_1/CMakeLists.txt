cmake_minimum_required(VERSION 3.29)

project(library_1 VERSION 1.0.0 LANGUAGES CXX DESCRIPTION "my description")

# This option changes the implicit behavior of CMake
# See https://cmake.org/cmake/help/latest/variable/BUILD_SHARED_LIBS.html
option(BUILD_SHARED_LIBS "Build as shared library" ON)

add_library(${PROJECT_NAME})
add_library(demo::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# add_library(MyStuff SHARED source1.cpp ...)
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION 2.0.0
    SOVERSION 2

    # This is for the Windows platform.
    # Check Craig Scott "Professional CMake", Chapter "Shared Library Versioning"
    DLL_NAME_WITH_SOVERSION TRUE
)

target_sources(${PROJECT_NAME}
    PRIVATE
    src/feature_set_1.cpp
    src/feature_set_2.cpp
    PUBLIC
    include/${PROJECT_NAME}/feature_set_1.hpp
    include/${PROJECT_NAME}/feature_set_2.hpp)

target_include_directories(library_1 PUBLIC include)
