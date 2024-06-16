## Summary

This example shows a configuration for a C++ project yielding an executable 
- It relies on one library and uses CMake's [`FetchContent`](https://cmake.org/cmake/help/latest/module/FetchContent.html) feature to include it.
- It has a configuration for releasing packages for all major platforms.
- These are refined for the Linux platform.

## What's New

### Summary

This example extends and modifies [example_3](../example_3/) in such a way that the Debian package will install the software and its dependencies below the install path `/opt/daixtrose/example_4-x.y.z`. In addition, the `RUNPATH` variables of the executable **and** the library `library_1` are set such that the `bin` and `lib` subdirectories of the install path are searched for dependencies.

## A Short Introduction to `RPATH`, `LD_LIBRARY_PATH`, and `RUNPATH` 

`RPATH` and `RUNPATH` denote the run-time search path hard-coded in an executable file or library for [`ELF`](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format) binaries. In contrast, `LD_LIBRARY_PATH` is an environment variable which is *also* considered during program start.  

So, all three variables point to search paths for dependencies. A couple of years ago, all these variables were relevant. You can read about the situation in 2016 in [Amir Rachum's article](https://amir.rachum.com/shared-libraries/#rpath-and-runpath) or watch [Craig Scott's CppCon 2019 talk "Deep CMake for Library Authors"](https://www.youtube.com/watch?v=m0DwB4OvDXk) for a deeper understanding.

When it was still available, `RPATH` was searched in *before* `LD_LIBRARY_PATH` while `RUNPATH` was searched in *after* `LD_LIBRARY_PATH`. The fact that `RPATH` was searched in *before* `LD_LIBRARY_PATH` yielded [security issues](https://en.wikipedia.org/wiki/Rpath#Security_considerations), and therefore `RPATH` was abandoned. 

The corresponding `CMAKE` variable is still called `INSTALL_RPATH` because the decision whether `RUNPATH` or `RPATH` is set is [up to the linker](https://gitlab.kitware.com/cmake/cmake/-/issues/25683). On modern systems `RUNPATH` is set and `RPATH` remains empty.  

### `RUNPATH` Settings

Check the `RUNPATH` settings of the executable. Note the difference between build directory and installed version! 

```bash
chrpath -l /opt/daixtrose/example_4-1.0.0/bin/example_4
```

yields

```
/opt/daixtrose/example_4-1.0.0/bin/example_4: RUNPATH=$ORIGIN:$ORIGIN/../lib
```

while 

```bash
chrpath -l build_example_4/example_4
```

yields

```
build_example_4/example_4: RUNPATH=$ORIGIN/_deps/library_1-build:
```

Hint: You can change the settings for the `build_example_4/example_4` executable by adding explicit settings for `BUILD_RPATH` in the CMake configuration.

### Impact on the Library Search

Please note, that `ldconfig` on Linux systems is configured such that system dependencies like e.g. `libm`, `ld-linux-x86-64`, and `libgcc_s` installed on the system obtain preference over the ones installed with the tool in the `lib` directory. This can be seen by comparing the output of a file listing in the `lib` directory with the results from calling `ldd` on the executable: 

```bash
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

Setting `LD_LIBRARY_PATH` will change the situation for `libm` and `libgcc_s`, but `linux-vdso.so.1` (part of the kernel that's exported into every program's address space when it's loaded) will not change and the dynamic linker `/lib64/ld-linux-x86-64.so.2` remains hardwired to its absolute system path (see [this article about it](https://www.baeldung.com/linux/dynamic-linker)): 

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


## `RUNPATH` for Dependencies

Please note, that there is another difference between `RPATH` and `RUNPATH` that must be fixed for legacy systems: `RUNPATH` is not transitive, i.e. it is not propagated through the dependency tree but only applies for direct dependencies. 

So, even if a specific directory is contained in your executable's `RUNPATH` settings, a library inside that runpath which is a dependency of a *direct* dependency can still be reported as missing, if the *direct* dependency does not have `RUNPATH` set accordingly.

So, if there are transitive dependencies, then you have to keep an eye on those dependencies, too and set `RUNPATH` for these accordingly via a command similar to 

```cmake
set_target_properties(my_dependency 
    PROPERTIES
    BUILD_RPATH_USE_ORIGIN ON
    INSTALL_RPATH "$ORIGIN:$ORIGIN/${libDir}")
```

The effect of the command is as follows: 

```bash
$ chrpath -l /opt/daixtrose/example_4-1.0.0/lib/liblibrary_1.so
/opt/daixtrose/example_4-1.0.0/lib/liblibrary_1.so: RUNPATH=$ORIGIN:$ORIGIN/../lib
```

Give it a try: If you omit this command, `RUNPATH` is not set for `library_1`:

```bash 
$ chrpath -l /opt/daixtrose/example_4-1.0.0/lib/liblibrary_1.so
/opt/daixtrose/example_4-1.0.0/lib/liblibrary_1.so: no rpath or runpath tag found.
```

Since `liblibrary_1.so` does not have its own non-system dependencies, the `RUNPATH` settings do not matter in `example_4`. It is only set for illustration.    

## Build Instructions and More

### Overview 

Here we illustrate recommended ways to use `cmake` in a **portable way**. See [the CMake command line tool documentation](https://cmake.org/cmake/help/latest/manual/cmake.1.html) for details. 

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

You can inspect the content of the Debian package using  

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
