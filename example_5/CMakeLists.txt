cmake_minimum_required(VERSION 3.29)

project(example_5 VERSION 1.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    src/features.cpp
    src/main.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
target_include_directories(${PROJECT_NAME} PUBLIC include)

# See https://github.com/daixtrose/cmake_utilities for what else you can do with FetchContent
include(FetchContent)

# FetchContent_Declare(
# library_1
# SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../library_1
# )

# FetchContent_MakeAvailable(library_1)

# target_link_libraries(
# ${PROJECT_NAME}
# PUBLIC

# # Here all the magic happens:
# # - The include paths are set accordingly
# # - The linker instructions are set accordingly
# # Hint: This requires sanity in the library's CMakeLists.txt
# demo::library_1
# )