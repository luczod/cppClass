### Types 
- A type declares how an object will be interpreted and used by the compiler.
- Every object in a C++ program has a type.
- A literal is a hardcoded value in a program.
- Long doube > double > float
- General rule is to use a double.
- General rule, use %g to print floating-point types.

### The std::byte Type

- System programmers sometimes work directly with raw memory, which is a collection of bits without a type. 
- Employ the std::byte type
- The std::byte type permits bitwise logical operations

### User-Defined Types

- User-defined types are types that the user can define
- Enumerations, Classes, Unions
- Classes are user-defined types
- Unions are dangerous and easy to misuse. 

### Plain-Old-Data Classes (PODs)

- Plain-old-data classes (PODs). PODs are simple containers. 
- Think of them as a sort of heterogeneous array of elements of potentially different types.
- Every POD begins with the keyword struct followed by the POD’s desired name.

### fully-Class

- The class keyword, which declares members private by default.
- struct is a class invariant, needs constructor
- constructor's name matches the class’s name. 
