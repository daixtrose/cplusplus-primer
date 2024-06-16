## Summary

This example shows a more elaborate configuration for a C++ project yielding an executable 
- It relies on one library and uses CMake's [`FetchContent`](https://cmake.org/cmake/help/latest/module/FetchContent.html) feature to include it
- It has configuration for releasing packages for all major platforms

## What's New

This example extends and modifies [example_3](../example_3/) in such a way that the Debian package will install the software and its dependencies below `/opt/daixtrose/example_4-x.y.z` and set the RUNPATH variable such that the `bin` and `lib` libraries are searched for dependencies.

Please note, that `ldconfig` on Linux systems is configured such that system dependencies like e.g. `libm`, `ld-linux-x86-64`, and `libgcc_s` installed on the system obtain preference over the ones installed with the tool in the `lib` directory. This can be seen by comparing the output of a file listing in the `lib` directory with the results from calling `ldd` on the executable: 

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

Setting `LD_LIBRARY_PATH` will change the situation for `libm` and `libgcc_s`, but `linux-vdso.so.1` (part of the kernel that's exported into every program's address space when it's loaded) and the dynamic linker `/lib64/ld-linux-x86-64.so.2` remains hardwired to its absolute system path (see [this article about it](https://www.baeldung.com/linux/dynamic-linker)): 

```bash
$ export LD_LIBRARY_PATH=/opt/daixtrose/example_4-1.0.0/lib
$ ldd /opt/daixtrose/example_4-1.0.0/bin/example_4
        linux-vdso.so.1 (0x00007ffdd5799000)
        liblibrary_1.so.2 => /opt/daixtrose/example_4-1.0.0/lib/liblibrary_1.so.2 (0x00007f9334c49000)
        libstdc++.so.6 => /opt/daixtrose/example_4-1.0.0/lib/libstdc++.so.6 (0x00007f9334a1d000)
        libc.so.6 => /opt/daixtrose/example_4-1.0.0/lib/libc.so.6 (0x00007f93347f4000)
        libm.so.6 => /opt/daixtrose/example_4-1.0.0/lib/libm.so.6 (0x00007f933470d000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f9334c55000)
        libgcc_s.so.1 => /opt/daixtrose/example_4-1.0.0/lib/libgcc_s.so.1 (0x00007f93346ed000)
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

You can inspect its content using  

```bash
dpkg -c build_example_4/example_4-1.0.0-Linux.deb
```

The procedure is similar for rpm files:

```bash
rpm -qlp build_example_4/example_4-1.0.0-Linux.rpm
```

### Installing the Debian Package

```bash
sudo dpkg -i build_example_4/example_4-1.0.0-Linux.deb
```

### Uninstalling the Debian package

```bash
sudo dpkg -r example_4
```

### RUNPATH settings

Check the `RUNPATH` settings of the executable. Note the difference between build directory and installed version! 

```bash
chrpath -l build_example_4/example_4
chrpath -l /opt/daixtrose/example_4-1.0.0/bin/example_4
```

