## Summary

This example shows a more elaborate configuration for a C++ project yielding an executable 
- It relies on one library and uses CMake's [`FetchContent`](https://cmake.org/cmake/help/latest/module/FetchContent.html) feature to include it
- It has configuration for releasing packages for all major platforms

This example extends and modifies [example_3](../example_3/) in such a way that the Debian package will install the software and its dependencies below `/opt/daixtrose/example_4-x.y.z` and set the RUNPATH variable such that the `bin` and `lib` libraries are searched for dependencies,

Please note that `ldconfig` on Linux systems is configured such, that system dependencies like e.g. `libm`. `ld-linux-x86-64`, and `libgcc_s` which are installed on the system obtain preference over the ones installed with the tool in the `lib` directory: 

```bash
$ chrpath -l  /opt/daixtrose/example_4-1.0.0/bin/example_4 
/opt/daixtrose/example_4-1.0.0/bin/example_4: RUNPATH=$ORIGIN:$ORIGIN/../lib
$ ls /opt/daixtrose/example_4-1.0.0/lib
ld-linux-x86-64.so.2  libgcc_s.so.1    liblibrary_1.so.2      libm.so.6       libstdc++.so.6.0.30
libc.so.6             liblibrary_1.so  liblibrary_1.so.2.0.0  libstdc++.so.6
$ ldd /opt/daixtrose/example_4-1.0.0/bin/example_4
        linux-vdso.so.1 (0x00007fff757fb000)
        liblibrary_1.so.2 => /opt/daixtrose/example_4-1.0.0/bin/../lib/liblibrary_1.so.2 (0x00007fabaab81000)
        libstdc++.so.6 => /opt/daixtrose/example_4-1.0.0/bin/../lib/libstdc++.so.6 (0x00007fabaa955000)
        libc.so.6 => /opt/daixtrose/example_4-1.0.0/bin/../lib/libc.so.6 (0x00007fabaa72c000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fabaa63a000)
        /lib64/ld-linux-x86-64.so.2 (0x00007fabaab8d000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007fabaa61a000)
```

## Build Instructions and More

### Overview 

Here we illustrate recommended ways to use `cmake`. In contrast to the earlier examples we call `cmake` from the top level and use it in a **portable way**. For completeness we also show the alternative variants which work on systems that have Gnu `make` available where you change into the build directory and call all commands from there. It is still recommended to get used to the portable versions. See [the CMake command line tool documentation](https://cmake.org/cmake/help/latest/manual/cmake.1.html) for details. 

### Preparation

Create a subdirectory `build_example_4` and prepare the build system for the source in `example_4` in this subdirectory:

```bash
cmake -D CMAKE_BUILD_TYPE=Release -B build_example_4 -S example_4
# for debug builds use   
# cmake -D CMAKE_BUILD_TYPE=Debug -B build_example_4 -S example_4
```

### Building the `example_4` project:

Call `cmake` from the top level like this:

```bash
cmake --build build_example_4 --config Release --target example_4
```

### Creating release packages

Call `cmake` from the top level like this:

```bash
cmake --build build_example_4 --config Release --target package
```

### Alternative Commands for Creating Releases on Linux 

Switch to the directory and omit the previously configured `Release` flag:

```bash
cd build_example_4
make package
```

On Linux, this yields `DEB`, `RPM`, and `TGZ` packages. Note, that CPack allows you to create the packages separately:

```bash
cd build_example_4 
cpack -G "DEB" # this yields the Debian package only
```

You can inspect its content using  

```bash
sudo dpkg -c example_4-1.0.0-Linux.deb
```

The procedure is similar for rpm files:

```bash
cpack -G "RPM"
rpm -qlp example_4-1.0.0-Linux.rpm
```

### Installing the Debian Package

```bash
sudo dpkg -i example_4-1.0.0-Linux.deb
```

### Uninstalling the Debian package

```bash
sudo dpkg -r example_4
```

### Miscellanneous

Check the `RUNPATH` settings of the executable 

```bash
cd build_example_4
chrpath -l example_4
```

Learn about the cmake options in this project by calling

```bash
cd build_example_4
cmake -LH -N ../example_4
```
