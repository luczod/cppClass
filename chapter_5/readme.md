### Interface
- An interface as a contract between classes that implement the interface and users (also called consumers) of that
class.
- There’s no interface keyword in C++. You have to define interfaces using antiquated inheritance mechanisms.
- In C++, interfaces are always pure­virtual classes.
- To require a derived class to implement the method, you can append the =0 suffix to a method definition.
- As a consumer, you can only deal in references or pointers to interfaces.

### Object composition
- Object composition is a design pattern where a class contains members of other class types.
- A pointer can be reseated, unlike references(&)
