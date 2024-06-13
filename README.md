# C++ Primer 

## Summary 

A short introduction to C++ which was quickly hacked together

## Useful Weblinks

- [C++ Reference](https://en.cppreference.com/)
  - This is a carefully crafted encyclopedia of C++ features with examples
  - The first stop for any question 
- [Matt Godbolt's Compiler Explorer](https://godbolt.org/) 
  - An online compiler tester
  - Use for testing small C++ code snippets
- [Craig Scott: "Professional CMake"](https://crascit.com/professional-cmake/)    
  - The one and only book you need about build systems 

## Build Instructions

### Example 1 

```bash
mkdir build_example_1
cd build_example_1/
cmake ../example_1/
make
```

### Library 1 

```bash
mkdir build_library_1
cd build_library_1/
cmake ../library_1/
make
```

### Example 3

Here we illustrate a different, recommended way to use `cmake`. See [the CMake command line tool documentation](https://cmake.org/cmake/help/latest/manual/cmake.1.html)

Create a subdirectory `build_example_3` and prepare the build system for the source in `example_3` in this subdirectory:

```bash
cmake -B build_example_3 -S example_3
```

Build the `example_3` project:

```bash
cmake --build build_example_3 --config Debug --target example_3
```

Check the `RUNPATH` settings of the executable 

```bash
cd build_example_3
chrpath -l example_3
```

Create a Debian package and inspect it 

```bash
cd build_example_3
cpack -G "DEB"
sudo dpkg -c example_3-1.0.0-Linux.deb
```

Install the Debian package

```bash
sudo dpkg -c example_3-1.0.0-Linux.deb
chrpath -l example_3 
```

Uninstall the package

```bash
sudo dpkg -r example_3
```