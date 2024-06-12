cmake_minimum_required(VERSION 3.29)

project(example_1)


add_executable(example_1 
    src/function_1.cpp
    src/function_2.cpp
    src/main.cpp
    )

target_include_directories(example_1 PUBLIC include)


# add_library(sample)
# target_sources(sample
# PRIVATE
# source/hello_there.cpp
# source/hello_there_impl.cpp
# source/hello_there_impl.hpp
# PUBLIC
# include/hello_there.hpp)
# target_include_directories(sample PUBLIC include)