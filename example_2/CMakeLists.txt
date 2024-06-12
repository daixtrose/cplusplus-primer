cmake_minimum_required(VERSION 3.29)

project(example_2 VERSION 1.0.0 LANGUAGES CXX)

add_executable(example_2 
    src/main.cpp
    )

add_subdirectory(../library_1 build_library_1)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    demo::library_1
    )
