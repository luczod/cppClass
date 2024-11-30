### Subscript and Offser

- int array_name[] {1,2,3,4};
- int \*pointer_name {array_name};

| Subscript Notation  | Offset Notation          |
| ------------------- | ------------------------ |
| array_name[index]   | \*(array_name + index)   |
| pointer_name[index] | \*(pointer_name + index) |


### Bounds Checking

- vector[0]: This syntax does not perform any bounds checking. If you attempt to access an index that is out of range (e.g., vector when the vector has fewer than 11 elements), it results in undefined behavior. This means that your program might crash, or it may return a garbage value without any warning.
- vector.at(0): In contrast, the at() method includes bounds checking. If you try to access an index that is out of range, it throws an std::out_of_range exception. This makes it safer to use, as it provides a clear indication of an error when accessing invalid indices

###  Performance

- vector[0]: Accessing elements using the subscript operator is generally faster because it does not incur the overhead of bounds checking.
- vector.at(0): While this method is slightly slower due to the additional checks, the performance difference is often negligible unless you're accessing elements in a tight loop where performance is critica