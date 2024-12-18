# C++ Primer 

## Summary 

A short introduction to C++. The examples build on top of each other. A special focus is put on the build configuration which is based on the goto-tool for building C++, namely [`CMake`](https://cmake.org/cmake/help/latest/). The idea is to have the build system configured correctly right from the beginning, and only then move on to learn how to code.      

## Useful Weblinks

### C++

- [C++ Reference](https://en.cppreference.com/)
  - This is a carefully crafted encyclopedia of C++ features with examples
  - The first stop for any question 
- [Matt Godbolt's Compiler Explorer](https://godbolt.org/) 
  - An online compiler tester
  - Use for testing small C++ code snippets
- [Jason Turner's GitHub landing page](https://github.com/lefticus)
  - [YouTube channel C++ Weekly](https://www.youtube.com/@cppweekly)
- [MattPD's C++ Links](https://github.com/MattPD/cpplinks)

### CMake 

- [Craig Scott: "Professional CMake"](https://crascit.com/professional-cmake/)    
  - The one and only book you need about build systems 
- [HSF - More Modern CMake](https://hsf-training.github.io/hsf-training-cmake-webpage/index.html)
- [Building a Dual Shared and Static Library with CMake](https://alexreinking.com/blog/building-a-dual-shared-and-static-library-with-cmake.html)

## List of Subprojects

- [Example 1](example_1/): The most basic build setup for an executable 
- [Library 1](library_1/): The most basic build setup for a library 
- [Example 2](example_2/): How to include libraries (primitive version using a specific directory) 
- [Example 3](example_3/): 
  - How to include libraries using `FetchContent`
  - How to configure CPack to obtain release packages  
- [Example 4](example_4/): 
  - Install in a tool-specific directory
  - Configure `RUNPATH`
  - Illustrate the effect of `LD_LIBRARY_PATH`
  
## Basic C++ Concepts Explained

This part is not yet written.

