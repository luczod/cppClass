### Pointer
- appending an asterisk(*) to the pointed-to type. (int\* my_ptr;)
- The format specifier for a pointer is %p.
- void pointers and std::byte pointers
- A pointer can be reseated, unlike references(&)

### Dereference Pointers
- Given an address, you can obtain the object residing there
- the dereference operator, the pointer declaration, and multiplication all use asterisks(*).

### The member-of-pointer operator
- Or arrow operator (->)

### Pointers Are Dangerous
- It’s not possible to convert a pointer to an array, which is a good thing.
- Buffer Overflows
- Writing to some memory that doesn’t belong to lower
- Can result in access violations, program crashes, security vulnerabilities, and corrupted data.

### References
- References are safer, more convenient versions of pointers.
- Declare references with the "&" declarator appended to the type name.
- int &my_ref;

### Forward-Linked Lists
- Each element holds a pointer to the next element.
- The last element in the linked list holds a nullptr.
- No change the memory location of any Element objects; Only modifying pointer values.
