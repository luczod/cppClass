#### Chapter 16: Streams

Rather than invoking a system call for each output element, an application can wait for multiple elements and then send them all together to improve performance. The queuing behavior is called **buffering**.When the stream empties
the buffered output, it’s called **flushing**.

### Listing

- Listing 16-1: Using cout and operator<< to write into stdout
- Listing 16-2: Refactoring Listing 16-1 by chaining output operators together
- Listing 16-3: A primitive calculator program using cin and operator<< to collect input
- Listing 16-5: A program that counts words from stdin until it encounters an EOF
- Listing 16-7: Refactoring Listing 16-5 to handle badbit with exceptions
- Listing 16-8: A program illustrating some of the manipulators available in the iomanip header
- Listing 16-9: A program illustrating how to implement an output operator "<<" for a vector
- Listing 16-10: A program illustrating how to implement an input operator ">>" for a deque
- Listing 16-14: A program opening the file lunchtime.txt and appending a message to it.
- Listing 16-15: A program that reads the text file numbers.txt and prints its maximum integer
- Listing 16-16: A factory function for generating ifstreams that handle errors with exceptions rather than failing silently
- Listing 16-17: Writing the message Hi to stdout using the ostreambuf_iterator class
- Listing 16-18: Constructing a string from cin using input stream buffer iterators
- Listing 16-19: A program using random access methods to read arbitrary characters in a
  text file
