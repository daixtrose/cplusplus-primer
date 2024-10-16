## Summary

This example shows two different ways to implement [polymorphism](https://en.wikipedia.org/wiki/Polymorphism_(computer_science)) in C++:

1. The classic approach using an [abstract class](https://en.cppreference.com/w/cpp/language/abstract_class) which is used to define an interface and from which the implementation inherits.
2. The modern approach using [concepts](https://en.cppreference.com/w/cpp/language/constraints) to declare features a type must have.

In addition, this directory contains an example about how to perform unit tests using the [ut testing framework](https://github.com/boost-ext/ut).

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

### Building the `polymorphism` project

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

## Code Explanations

### Classic Approach

In classic C++, interfaces are defined via [abstract base classes](https://en.cppreference.com/w/cpp/language/abstract_class) from which the implementation (publicly) inherits. In this example, we have defined such an abstract class:

```c++
class ISuperCoolFeatures {
public:
    virtual std::string coolFeature() const = 0; // Pure virtual function
    virtual void set(std::string s) = 0; // Pure virtual function
    virtual ~ISuperCoolFeatures() = default; // Virtual destructor
};
```

Instead of defining the member function body (which is possible in a regular class), the member functions of an abstract interface class are declared "pure virtual" by adding `= 0` to their declaration.

Any so-called **implementation** of the interface publicly inherits from this abstract base class and then declares and defines member functions that match the declarations of the pure virtual functions in the abstract interface class:

```c++
class Impl
    : public ISuperCoolFeatures {

// ... private members and member functions omitted ...

public:
    std::string coolFeature() const override { return s_; }
    void set(std::string s) override
    {
        // ... implementation omitted ...
    }
};
```

A variable (aka instantiation) of type `Impl` can be passed as argument to any function that expects an argument of its interface type `ISuperCoolFeatures`.

In our example, we define a function which has one argument of type `ISuperCoolFeatures`, and returns a `std::string`:

```c++
std::string consume(ISuperCoolFeatures& f);
```

We then pass an argument of type `Impl` to it, e.g. like this:

```c++
Impl i;
consume(i);
```

Since it is best practice, the example code puts the type and function definitions into namespaces.

### Modern Approach

In modern C++, interfaces can also be defined via [concepts](https://en.cppreference.com/w/cpp/language/constraints), which can be used to declare what features a concrete class must have. It is slightly more powerful in what can be described.

It also has a great advantage that it is non-intrusive, i.e. it does not require a concrete class to inherit from a certain interface class. This is of advantage when you are not owner of the code of a class that you want to use and cannot change its declaration and definition.

This means that objects of completely unrelated classes can be passed as arguments to a member function (aka method) or a free function, if they all have certain member functions defined.

From a code structuring point of view, this means that the cohesion between different parts of the code is reduced.

In this example, we have defined such an interface specification as a concept:

```c++
template <typename T>
concept has_super_cool_features = requires(T t, std::string s) {
    { t.coolFeature() } -> std::convertible_to<std::string>;
    { t.set(s) } -> std::same_as<void>;
};
```

We then declare a function that takes arguments whose type adheres to the constraints defined by the concept:

```c++
std::string consume(has_super_cool_features auto& s);
```

and can use it in the very same way like in the classic case:

```c++
Impl i;
consume(i);
```

In this approach, our implementation is defined **without** inheritance:

```c++
class Impl {

// ...

public:
    std::string coolFeature() const { /* ... some code ... */ }
    void set(std::string s)
    {
        // code omitted
    }
};
```

To catch errors in the implementation before the class gets uses somewhere else in the code, it suffices to check against the concept like this:

```c++
static_assert(has_super_cool_features<Impl>);
```

Please note, that this modern approach with its advantages in code decoupling, flexibility and a more powerful description of its features comes at a price:

Functions that use `<some concept> auto` as parameter type are *generic* and this requires either their implicit or their explicit instantiation.

Implicit instantiation of the function can take place if its **definition** is visible at the point of usage.

In this example, we use explicit instantiation to show the possibility to clearly separate the definition (implementation) of the generic function from its declaration.

You can find the definition of `consume` in `src/consume_class_that_adheres_to_concept.ipp` which is then included into `src/consume_class_that_adheres_to_concept.cpp`. In the latter file we also place all explicit instantiations of `consume`:

```c++
// explicit template instantiation
template std::string consume<Impl>(Impl&);
```

As an alternative, the *definition* of `consume` could be in the header `include/polymorphism/consume_class_that_adheres_to_concept.hpp`. Then the explicit template instantiation is no longer required.

## Testing

In this example, we use [µt](https://github.com/boost-ext/ut) as testing framework.

The one-header version of it is pulled into the project via the CMake call

```cmake
FetchContent_Declare(ut
    URL https://raw.githubusercontent.com/boost-ext/ut/refs/heads/master/include/boost/ut.hpp
    DOWNLOAD_NO_EXTRACT TRUE
    SOURCE_DIR ut
)
FetchContent_MakeAvailable(ut)
```

and the directory to which the header is downloaded is added to the search path set for the build of the test executables:

```cmake
target_include_directories(test_consume PUBLIC "${ut_SOURCE_DIR}")
```

Please refer to [this slidedeck](https://boost-ext.github.io/ut/denver-cpp-2019/#/) for further documentation of this test library.