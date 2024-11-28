#### Chapter 18: Algorithms

- Non-Modifying Sequence Operations: is an algorithm that performs computation over a sequence but **doesn’t modify** the sequence in any way. Ex: for_each, count, is_permutation.

- Mutating Sequence Operations: is an algorithm that performs computation over a sequence and is **allowed to modify** the sequence in some way. Ex: copy, move, transform.

- Sorting and Related Operations: is an algorithm that reorders a sequence in some desired way. Each sorting algorithm has two versions: one that takes a function object called a comparison operator and one that uses operator "<". Ex: sort, nth_element, is_sorted.

- Binary Search Algorithms: assume that a target sequence **is already sorted**. These algorithms have desirable complexity characteristics compared with generic search over an unspecified sequence. Ex: binary_search, upper_bound, equal_range.

- Partitioned Algorithms: contains two contiguous, distinct groups of elements. These groups don’t mix, and the first element of the second distinct group is called the partition point. Ex: is_partitioned,

- Merging Algorithms: merge two sorted target sequences such that the resulting sequence contains copies of both target sequences and is also sorted. Ex: merge.

- Extreme-Value Algorithms: determine minimum and maximum elements or place limits on the minimum or maximum value of an element. Ex: min and max, clamp.

- Numeric Operations: provides algorithms well suited to numeric operations. Ex: iota, accumulate, accumulate, inner_product.

- Boost Algorithm is a large algorithm library that overlaps partially with the standard library. Ex: boyer_moore, find_not, is_palindrome.

### Parallel algorithms

An algorithm that requires synchronization among entities is usually non-vectorizable
because the same entity could attempt to acquire a lock multiple times, resulting in a deadlock.

C++ Standard doesn’t specify the precise meaning of these execution policies
because different platforms handle parallelism differently.
