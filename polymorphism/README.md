## Summary

This example shows two different ways to implement [polymorphism](https://en.wikipedia.org/wiki/Polymorphism_(computer_science)) in C++:

1. The classic approach using an [abstract class](https://en.cppreference.com/w/cpp/language/abstract_class) which is used to define an interface and from which the implementation inherits.
2. The modern approach using [concepts](https://en.cppreference.com/w/cpp/language/constraints) to declare features a type must have. 

In addition, this directory contains an example about how to perform unit tests using the [ut testing framework](https://github.com/boost-ext/ut). 

## 

## Build Instructions 

### Preparation

Create a subdirectory `build_polymorphism` and prepare the build system for the source located in `polymorphism` in this subdirectory: For release builds use

```bash
cmake -D CMAKE_BUILD_TYPE=Release -B build_polymorphism -S polymorphism
```
For debug builds use   

```bash
cmake -D CMAKE_BUILD_TYPE=Debug -B build_polymorphism -S polymorphism
```


### Building the `polymorphism` project:

Call `cmake` from the top level like this:

```bash
cmake --build build_polymorphism --config Release --target polymorphism --parallel
```

## Test Instructions

### Build the tests

```bash
VERBOSE=1 cmake --build build_polymorphism --clean-first --config Debug --target all --parallel
```

### Run the tests

```bash
ctest --test-dir build_polymorphism  --output-on-failure --build-config Debug
```

