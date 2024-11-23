## C++ CRASH COURSE

### Josh Lospinoso: 

(https://github.com/JLospinoso/ccc)

# Install Software

1. Follow the instructions in Chapter 1 for setting up a development environment.
2. [Download and install CMake](https://cmake.org/download/)
3. [Download and install Boost](https://www.boost.org/doc/libs/1_68_0/more/getting_started/index.html)
4. [Download and install Git](https://git-scm.com/downloads)

```
cd ccc
git submodule init
git submodule update
mkdir build
cd build
cmake ..
cmake --build .
```

Your build directory should now contain requisite files for building on your current platform. On Windows, for example, you should find a `.sln` Visual Studio Solution file. On macOS/Linux, you should find a `make` file

### Contents

- Chapter 1:  Up and Running
- Chapter 2:  Types
- Chapter 3:  Reference Types
- Chapter 4:  The Object Life Cycle
- Chapter 5:  Runtime Polymorphism
- Chapter 6:  Compile-Time Polymorphism
- Chapter 7:  Expressions
- Chapter 8:  Statements
- Chapter 9:  Functions
- Chapter 10: Testing
- Chapter 11: Smart Pointers
- Chapter 12: Utilities 
- Chapter 13: Containers 
- Chapter 14: Iterators 
- Chapter 15: Strings 
- Chapter 16: Streams
- Chapter 17: Filesystems
- Chapter 18: Algorithms
- Chapter 19: Concurrency and Parallelism
- Chapter 20: Network Programming with Boost Asio
- Chapter 21: Writing Applications