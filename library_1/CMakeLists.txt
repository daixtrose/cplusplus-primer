cmake_minimum_required(VERSION 3.29)

project(library_1 VERSION 1.0.0 LANGUAGES CXX DESCRIPTION "my description")

add_library(${PROJECT_NAME} SHARED)
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
