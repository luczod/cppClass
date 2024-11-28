#### Chapter 17: Filesystems

Rather than invoking a system call for each output element, an application can wait for multiple elements and then send them all together to improve performance. The queuing behavior is called **buffering**.When the stream empties
the buffered output, it’s called **flushing**.

### Listing

- filesystem: Constructing std::filesystem::path
- Listing 17-2: A program printing various decompositions of a path
- Listing 17-3: Manipulating a path using modifier methods.
- Listing 17-4: A program using several path composing functions.
- Listing 17-5: A program inspecting files
- Listing 17-6: A program illustrating several methods for interacting with the filesystem.
- Listing 17-7: A file- and directory-listing program that uses std::filesystem::directory_iterator to enumerate a given directory.
- Listing 17-8: A file- and directory-listing program that uses std::filesystem::recursive_directory_iterator
- Listing 17-9: Searching the Windows System32 directory for Windows portable executable files
