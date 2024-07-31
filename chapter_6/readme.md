### Templates
- C++ achieves compile-time polymorphism through templates.
- A template is a class or function with template parameters
- You declare templates with a template prefix(angle brackets < >)
- the template parameters(any type, int, user-defined class...)
- Resource acquisition is initialization (RAII)
- Templates are type safe. During template instantiation, the compiler pastes
in the template parameters.
- Non-Type Template Parameters (values)
- Variadic Templates

### Static cast
- The reason you might need static_cast is that, generally, implicit casts aren’t reversible.
- Narrow_cast, it is a homemade explicit templated conversion function,
- Used when values could be narrowed throwing an exception in this case, whereas static_cast doesn't throw one.

### Generic programming
- Templates allow the compiler to instantiate a custom class or function based
on the types in use

### Type Checking
- duck-typed languages might blow up at runtime, templates might blow up at compile time.
- Concept, Requires Expressions, static_assert
