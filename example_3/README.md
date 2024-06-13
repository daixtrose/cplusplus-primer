## Summary

This example shows a more elaborate configuration for a C++ project yielding an executable 
- It relies on one library and uses CMake's [`FetchContent`](https://cmake.org/cmake/help/latest/module/FetchContent.html) feature to include it
- It has configuration for releasing packages for all major platforms

## Build Instructions and More

### Overview 

Here we illustrate recommended ways to use `cmake`. In contrast to the earlier examples we call `cmake` from the top level and use it in a **portable way**. For completeness we also show the alternative variants which work on systems that have Gnu `make` available where you change into the build directory and call all commands from there. It is still recommended to get used to the portable versions. See [the CMake command line tool documentation](https://cmake.org/cmake/help/latest/manual/cmake.1.html) for details. 

### Preparation

Create a subdirectory `build_example_3` and prepare the build system for the source in `example_3` in this subdirectory:

```bash
cmake -D CMAKE_BUILD_TYPE=Release -B build_example_3 -S example_3
# for debug builds use   
# cmake -D CMAKE_BUILD_TYPE=Debug -B build_example_3 -S example_3
```

### Building the `example_3` project:

Call `cmake` from the top level like this:

```bash
cmake --build build_example_3 --config Release --target example_3
```

### Creating release packages

Call `cmake` from the top level like this:

```bash
cmake --build build_example_3 --config Release --target package
```

### Alternative Commands for Creating Releases on Linux 

Switch to the directory and omit the previously configured `Release` flag:

```bash
cd build_example_3
make package
```

On Linux, this yields `DEB`, `RPM`, and `TGZ` packages. Note, that CPack allows you to create the packages separately:

```bash
cd build_example_3 
cpack -G "DEB" # this yields the Debian package only
```

You can inspect its content using  

```bash
sudo dpkg -c example_3-1.0.0-Linux.deb
```

The procedure is similar for rpm files:

```bash
cpack -G "RPM"
rpm -qlp example_3-1.0.0-Linux.rpm
```

### Installing the Debian Package

```bash
sudo dpkg -i example_3-1.0.0-Linux.deb
```

### Uninstalling the Debian package

```bash
sudo dpkg -r example_3
```

### Miscellanneous

Check the `RUNPATH` settings of the executable 

```bash
cd build_example_3
chrpath -l example_3
```
