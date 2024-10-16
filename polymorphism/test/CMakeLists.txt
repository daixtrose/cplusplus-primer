cmake_minimum_required(VERSION 3.29)

include(FetchContent)

FetchContent_Declare(ut
    URL https://raw.githubusercontent.com/boost-ext/ut/refs/heads/master/include/boost/ut.hpp
    DOWNLOAD_NO_EXTRACT TRUE
    SOURCE_DIR ut
)
FetchContent_MakeAvailable(ut)

add_library(polymorphism_lib
    ../src/consume_class_that_adheres_to_concept.cpp
    ../src/consume_class_with_interface.cpp
)

target_compile_features(polymorphism_lib PUBLIC cxx_std_23)
target_include_directories(polymorphism_lib PUBLIC ../include)

add_executable(test_consume
    test_consume.cpp
)

target_compile_features(test_consume PUBLIC cxx_std_23)

target_include_directories(test_consume PUBLIC ../include)
target_include_directories(test_consume PUBLIC "${ut_SOURCE_DIR}")

target_link_libraries(test_consume PRIVATE polymorphism_lib)

add_test(
    NAME test_consume
    COMMAND test_consume
)