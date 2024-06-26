cmake_minimum_required(VERSION 3.29)

project(cplusplus-primer)

# See https://github.com/daixtrose/cmake_utilities for what else you can do with FetchContent
include(FetchContent)

FetchContent_Declare(library_1 SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/library_1)

# FetchContent_Declare(example_1 SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/example_1)
FetchContent_Declare(example_2 SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/example_2)

# FetchContent_Declare(example_3 SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/example_3)
# FetchContent_Declare(example_4 SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/example_4)
FetchContent_MakeAvailable(library_1)

# FetchContent_MakeAvailable(example_1)
FetchContent_MakeAvailable(example_2)

# FetchContent_MakeAvailable(example_3)
# FetchContent_MakeAvailable(example_4)

# add_subdirectory(example_1)
# add_subdirectory(example_2)
# add_subdirectory(example_3)
# add_subdirectory(example_4)
# add_subdirectory(library_1)
