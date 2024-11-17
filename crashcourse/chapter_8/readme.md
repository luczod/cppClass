### Namespaces

- Namespaces prevent naming conflicts. In large projects or when importing libraries,
- Namespaces are essential for disambiguating exactly the symbols you’re looking for.
- By default, all symbols you declare go into the global namespace.
- Use the scope-resolution "::" operator to specify the fully qualified name of a symbol.
- This allows you to prevent naming conflicts in large projects or when you’re using a thirdparty library.

### Iterator

- An iterator is an object that supports operator!=, operator++, and operator*.
- the dereference operator "*"
- Iterating with an Index
- Ranged Based for Loops (Range Expressions)

### Jump Statements

- Including the break, continue, and goto statements, transfer control flow.
- Labels give statements a name, and they have no direct impact on the program.
- To assign a label, prepend a statement with the desired name of the label followed by a semicolon.
- In modern C++, there is no good role for goto statements. Don’t use them.
- In most C code, you might see goto used as a primitive error-handling mechanism.


