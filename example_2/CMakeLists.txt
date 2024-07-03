cmake_minimum_required(VERSION 3.29)

project(example_2 VERSION 1.0.0 LANGUAGES CXX)

add_executable(example_2
    src/main.cpp
)

# We define the source location (../library_1) and the build directory (build_library_1)
# The build directory could also be a shared location like e.g.
# add_subdirectory(../library_1 ../build_library_1)
# but be aware of parallel builds!
# In general, keep builds separate. KISS principle!
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../library_1 build_library_1)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    demo::library_1
)
