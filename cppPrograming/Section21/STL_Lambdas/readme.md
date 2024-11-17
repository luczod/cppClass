### Structure of a Lambda Expression

- [], (), -> return_type, specifiers, { return; }
- [] (int x) { std::cout << x; };
- [] (int x) { std::cout << x; }();
- auto foo = [] () { std::cout << "foo"; };
- foo();
- auto foo = [] (int x, int y) { return x + y; };
- foo();
- Compiler-generated closure
- Compiler create a function object


