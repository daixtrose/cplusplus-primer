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

#### Overview 

Here we illustrate recommended ways to use `cmake`. See [the CMake command line tool documentation](https://cmake.org/cmake/help/latest/manual/cmake.1.html)

#### Preparation

Create a subdirectory `build_example_3` and prepare the build system for the source in `example_3` in this subdirectory:

```bash
cmake -D CMAKE_BUILD_TYPE=Release -B build_example_3 -S example_3
# for debug builds use   
# cmake -D CMAKE_BUILD_TYPE=Debug -B build_example_3 -S example_3
```

#### Building the `example_3` project:

Call `cmake` from the top level like this:

```bash
cmake --build build_example_3 --config Release --target example_3
```

#### Creating release packages

Call `cmake` from the top level like this:

```bash
cmake --build build_example_3 --config Release --target package
```

Alternatively switch to the directory and omit the previously configured `Release` flag:

```bash
cd build_example_3
make package
```



On Linux, this yields `DEB`, `RPM`, and `TGZ` packages. 

Alternatively CPack allows you to create a Debian/RPM/TGZ package only. Example:

```bash
cd build_example_3 
cpack -G "DEB"
```

You can inspect its content using  

```bash
sudo dpkg -c example_3-1.0.0-Linux.deb
```

or (after issuing the command `cpack -G "RPM"`) inspect the content of the rpm file like this:

```bash
rpm -qlp example_3-1.0.0-Linux.rpm
```

#### Installing the Debian package

```bash
sudo dpkg -i example_3-1.0.0-Linux.deb
```

#### Uninstalling the Debian package

```bash
sudo dpkg -r example_3
```

#### Miscellanneous

Check the `RUNPATH` settings of the executable 

```bash
cd build_example_3
chrpath -l example_3
```
