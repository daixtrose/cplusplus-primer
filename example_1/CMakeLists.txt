cmake_minimum_required(VERSION 3.29)

project(example_1)

add_executable(example_1 
    src/function_1.cpp
    src/function_2.cpp
    src/main.cpp
    )

target_include_directories(example_1 PUBLIC include)
