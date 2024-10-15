cmake_minimum_required(VERSION 3.29)

project(example_5 VERSION 1.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    src/consume_class_with_interface.cpp
    src/consume_class_that_adheres_to_concept.cpp
    src/main.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
target_include_directories(${PROJECT_NAME} PUBLIC include)
