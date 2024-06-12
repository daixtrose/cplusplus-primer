cmake_minimum_required(VERSION 3.29)

project(library_1 VERSION 1.0.0 LANGUAGES CXX)

add_library(${PROJECT_NAME})
add_library(demo::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    src/feature_set_1.cpp
    src/feature_set_2.cpp
    PUBLIC
    include/library_1/feature_set_1.hpp
    include/library_1/feature_set_2.hpp)

target_include_directories(library_1 PUBLIC include)
