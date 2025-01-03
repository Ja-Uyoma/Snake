# Building with CMake

## Dependencies

For a list of dependencies, refer to [conanfile.py](conanfile.py).

Here are the steps for install the dependencies:

```sh
conan install conanfile.py --build=missing
```

## Build

This project doesn't require any special command-line flags to build to keep things simple.

Here are the steps for building in release mode with a single-configuration generator, like
Ninja or Unix Makefiles:

```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
```
Here are the steps for building in release mode with a multi-configuration generator, like
Ninja Multi-Config or Visual Studio:

```sh
cmake -S . -B build -G 'Ninja Multi-Config'
cmake --build build --config Release
```

## Install

This project doesn't require any special command-line flags to install to keep things simple.
As a prerequisite, the project has to be built with the above commands already.

The following commands require at least CMake 3.15 to run, as that is the version in which
[Install a Project][1] was added.

Here is the command for installing the release mode artifacts with a single-configuration generator,
like Ninja or Unix Makefiles:

```sh
cmake --install build
```

Here is the command for installing the release mode artifacts with a multi-configuration generator
like Ninja Multi-Config:

```sh
cmake --install build --config Release
```

[1]: https://cmake.org/cmake/help/latest/manual/cmake.1.html#install-a-project

