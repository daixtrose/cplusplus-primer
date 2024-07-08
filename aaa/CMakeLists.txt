cmake_minimum_required(VERSION 3.29)

project(aaa 
    VERSION 2.0.1 
    LANGUAGES CXX 
    DESCRIPTION "A simple demo library")

option(BUILD_SHARED_LIBS "Build as shared library" ON)

add_library(${PROJECT_NAME})
add_library(demo::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# explicitly say which C++ standard to be used    
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)


set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 2

    # This is for the Windows platform.
    # Check Craig Scott "Professional CMake", Chapter "Shared Library Versioning"
    DLL_NAME_WITH_SOVERSION TRUE
)

target_sources(${PROJECT_NAME}
    PRIVATE
    src/bar.cpp
    src/foo.cpp
    PUBLIC
    include/${PROJECT_NAME}/bar.hpp
    include/${PROJECT_NAME}/foo.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

include(${CMAKE_CURRENT_LIST_DIR}/CMakeListsCPackConfiguration.txt)