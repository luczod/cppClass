### Allocation
- A variable is simply an object that has a name.
- Every object requires storage. You reserve storage for objects in a process called allocation.
- An object’s storage duration begins when the object is allocated andends when the object is deallocated.
- A data buffer (or just buffer) is a region of memory used to store data temporarily while it is being moved from one place to another.

### Static Members
- Class that aren’t associated with a particular instance of the class.
- The scope resolution operator ::

### Inheritance
- It defines the inheritance relationship using the : Superclass syntax.
- a class invariant is a feature of a class that is always true

### Standard Exception Classes
- Logic Errors
- Runtime Errors
- Language Support Errors

### Copy assignnment
- The copy assignment operator uses the operator= syntax
- Copy constructor and assignment operator are used to perform deep copy when an object contains pointer members that point to dynamically allocated memory.
- you can define multiple functions with the same name but with different parameters
- the compiler will automatically call the correct version depending on  arguments.

### Move constructor
***the move constructor and move assignment operator is to transfer the resources (such as memory) owned by an object to another object. It is used to optimize the performance of an application by reducing the amount of data copying that is needed.***

***In short, the objective behind copy and assignment operator is to avoid shallow copy and perform deep copy, whereas the objective behind move constructor and move assignment operator is to transfer the ownership of the resources held by the source object to the destination object in an efficient manner.The move constructor and move assignment operator make use of rvalue references to move the contents of one object to another.***


### Lvalue and Rvalue References
- In C++, an expression can be categorized as either an Lvalue or an Rvalue(raw value)
- An Lvalue refers to an object that has an identifiable memory address and can be on the \_left-hand side\_ of an assignment operator(=)
- Lvalue can be modified, whereas an rvalue cannot be modified.
- An Rvalue refers to an object that does not have an identifiable memory address and can only be on the \_right-hand side\_of an assignment operator
- The inability to take the address(&) of an R-value is one of the distinguishing characteristics that differentiate it from an L-value.

