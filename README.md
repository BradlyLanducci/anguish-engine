# Anguish Engine

## Building

#### Requirements:
 - Conan
 - CMake
 - C++ Compiler

#### Compiling core library and example project:
 1. ```conan install . --output-folder=<build_folder> --build=missing -pr=<conan_profile>```
 2. ```cd build/<build_type>/generators```
 3. ```cmake ../../.. -DCMAKE_BUILD_TYPE=<build_type> -DCMAKE_TOOLCHAIN_FILE=./conan_toolchain.cmake -G='Ninja''```
 4. ```ninja```
