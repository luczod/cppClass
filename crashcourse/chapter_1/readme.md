### cmd

- sudo apt-get install build-essential gdb
- sudo apt install clang-format
- ./binary-file

### Links
- https://cplusplus.com/
- https://www.youtube.com/watch?v=2VokW_Jt0oM
- https://cppreference.com/

### The Compiler Tool Chain

- The preprocessor: When the preprocessor finishes processing a source file, it produces a single translation unit
- Compiler: Work on one translation unit at a time,so each translation unit corresponds to a single object file.
- Linker: Generates programs from object files

### Translation Unit
- The number of translation units is determined by the number of standalone .cpp files in your project, regardless of whether they're embedded in other files
- The number of translation units manageable to optimize compilation time and maintainability
- Techniques like precompiled headers or incremental linking to improve compilation performance

### printf Format Specifiers

- %d : int
