## Summary

This example shows a minimal configuration for a C++ project yielding a library. 

## Build Instructions

### Build a Static Library

```bash
mkdir build_library_1
cd build_library_1/
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=FALSE ../library_1
make
```

### Build a Shared Library

```bash
mkdir build_library_1
cd build_library_1/
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=TRUE ../library_1
make
```


Hint: there are more options to be considered for building stuff, see the other examples.