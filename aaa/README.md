## Summary

This example shows a minimal configuration for a C++ project yielding a library. 

## Build Instructions and More

### Overview 

Here we illustrate recommended ways to use `cmake` in a **portable way**. See [the CMake command line tool documentation](https://cmake.org/cmake/help/latest/manual/cmake.1.html) for details. 

### Preparation

Create a subdirectory `build_aaa` and prepare the build system for the source in `aaa` in this subdirectory:

```bash
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=TRUE -B build_aaa -S aaa --fresh
```

For debug builds use the option `-DCMAKE_BUILD_TYPE=Debug` and for static libraries use the option `-DBUILD_SHARED_LIBS=FALSE`.


### Building the `aaa` project:

Call `cmake` from the top level like this:

```bash
cmake --build build_aaa --config Release --target aaa --clean-first
```

### Creating release packages

Call `cmake` from the top level like this:

```bash
cmake --build build_aaa --config Release --target package
```

You can inspect the content of the Debian package using  

```bash
dpkg -c build_aaa/aaa-2.0.1-Linux.deb
```

The procedure is similar for rpm files:

```bash
rpm -qlpv build_aaa/aaa-2.0.1-Linux.rpm
```

### Installing the Debian Package

```bash
sudo dpkg -i build_aaa/aaa-2.0.1-Linux.deb
```

### Uninstalling the Debian package

```bash
sudo dpkg -r aaa
```

