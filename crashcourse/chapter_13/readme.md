#### Chapter 13: Containers

A container is a special **data structure** that stores objects in an organized
way that follows specific access rules. There are three kinds of containers:

- Sequence containers store elements consecutively, as in an array.
- Associative containers store sorted elements.
- Unordered associative containers store hashed objects

Associative and unordered associative containers offer rapid search for individual elements.
All containers are RAII wrappers around their contained objects, so they manage the storage durations
and lifetimes of the elements they own.
