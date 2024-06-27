cmake_minimum_required(VERSION 3.29)

project(cplusplus-primer)

include(ExternalProject)

foreach(subproject example_1 example_2 example_3 example_4 library_1)
    ExternalProject_Add(${subproject}
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${subproject}
        STEP_TARGETS build
        INSTALL_COMMAND ""
    )
endforeach()
