cmake_minimum_required(VERSION 3.29)

project(example_3 VERSION 1.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    )

include(FetchContent)

FetchContent_Declare(
    library_1
    SOURCE_DIR ../library_1
)

FetchContent_MakeAvailable(library_1)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    # Here all the magic happens: 
    # - The include paths are set accordingly 
    # - The linker instructions are set accordingly 
    # Hint: This requires sanity in the library's CMakeLists.txt    
    demo::library_1 
    )

# Package-specific Settings

install(TARGETS ${PROJECT_NAME} library_1)
# These are project-specific
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "Daixtrose Engineering")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An example project")
set(CPACK_PACKAGE_CONTACT "daixtrose.engineering@gmx.de")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Markus Werle")

# These lines tend to be the same for every project
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set(CPACK_VERBATIM_VARIABLES TRUE)

# This is what writes out the input file for cpack
include(CPack)
