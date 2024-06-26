cmake_minimum_required(VERSION 3.29)

project(cplusplus-primer)

foreach(subproject example_1 example_2 example_3 example_4 library_1)
    message(STATUS "Creating '${CMAKE_CURRENT_BINARY_DIR}/build_${subproject}'")
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/build_${subproject})
    add_custom_target(cplusplus-primer-${subproject} ALL
        COMMAND ${CMAKE_COMMAND} -B ${CMAKE_CURRENT_BINARY_DIR}/build_${subproject} -S ${CMAKE_CURRENT_SOURCE_DIR}/${subproject}
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_CURRENT_BINARY_DIR}/build_${subproject}
    )
endforeach()
