### Logical Opertators
- Each performs a Boolean operation at the bit level and returns an integral type matching its operands.
- Shorter integral types are promoted to int types.
- Integral types can also be promoted to floating-point types during arithmetic operation.
- C++ is a bit overzealous in silently converting types.

### casting and promotion
- Casting is when you have an object of one type and need to convert it to another type.
- Promotion is the set of rules for interpreting literals.
- braced initialization doesn’t permit narrowing conversions.

### Member Access Operators
- subscript "[]", indirection "*", address-of "&", member-of-object ".", and member-of-pointer "->"
- literals: constant values that you use directly in your programs.

### Buckets
- When you request memory, the environment allocates a whole bucket, even if you didn’t request all the memory.

### Namespaces

- Namespaces prevent naming conflicts. In large projects or when importing libraries,
- Namespaces are essential for disambiguating exactly the symbols you’re looking for.
- By default, all symbols you declare go into the global namespace.
- Use the scope-resolution "::" operator to specify the fully qualified name of a symbol.
- This allows you to prevent naming conflicts in large projects or when you’re using a thirdparty library.


