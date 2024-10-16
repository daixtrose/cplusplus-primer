cmake_minimum_required(VERSION 3.29)

project(polymorphism VERSION 1.0.0 LANGUAGES CXX)

option(POLYMORPHISM_ENABLE_TESTING "enable testing for polymorphism" ${PROJECT_IS_TOP_LEVEL})

add_executable(${PROJECT_NAME}
    src/consume_class_with_interface.cpp
    src/consume_class_that_adheres_to_concept.cpp
    src/main.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(POLYMORPHISM_ENABLE_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()
