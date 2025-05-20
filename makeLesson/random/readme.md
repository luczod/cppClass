#### Makefile complexity
- As a project increases in size so can its Makefile.
- Add in cross-plataform options and flags and the complexity.
- the Makefile for the Linux kernel is 2082 line long!
- So now we need to automate the creation of Makefiles so that Make can automate the compiling of the source code!
- This is where CMake fits in, I like to think of it as "Create Make" but actually the "C" in CMake stands for "cross-platform".


#### CMake
- CMake uses a configuration file called CMakelists.txt
    a. Define you project in CMakeLists.txt
    b. Run CMake to create the Makefile
    c. Build your project using Make
    d. Add code, fix things, etc then jump to step c
    e. If you add new .c files or alter the dependencies then jump to step a.

#### Out-of-source builds
- Traditionally Makefile are placed in the same directory as the source code
    1. You go into the source directory and then run Make
- But CMake is different. The Makefile is generated in a different directory
    1. The CMakeLists.txt is in the source directory, but the automatically generated build files are separate, so as not to overwhelm your source directory
- /home/user/src/hellow
    a. hellow.c
    b. CMakeLists.txt
    c. build/

```shell
cd build/
cmake .. # run CMakeLists.txt
```
- build/
    - Makefile
    - CMakeCache.txt
    - cmake_install.cmake
    - CMakeFiles/

```shell
cd build/
make
```
- build/
    - Makefile
    - CMakeCache.txt
    - cmake_install.cmake
    - CMakeFiles/
    - hellow (binary)