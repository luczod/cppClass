### Chapter 19: Concurrency and Parallelism

Sharing and Coordinating: One thread will increment the integer while the other decrements it. To modify a variable, each thread must read the variable’s current value, perform an addition or subtraction operation, and then write the variable to memory. Withoutsynchronization, the two threads will perform these operations in an undefined, interleaved order. Such situations are sometimes called **race conditions**.

A Mutual Exclusion Algorithm (Mutex) is a mechanism for preventing multiple threads from accessing resources simultaneously. Mutexes are synchronization primitives that support **two operations: lock and unlock**.

A Condition variable is a synchronization primitive that blocks one or more threads until **notified**. Another thread can notify the condition variable.

Parallel Algorithms: the stdlib’s algorithms, many of which take an optional **first argument called its execution policy** encoded by a std::execution value. In supported environments, there are three possible values: seq, par, and par_unseq.The latter two options indicate that you want to execute the algorithm in parallel.

#### Contents

- goat_rodeo: An illustration of how disastrous unsynchronized, mutable, shared data access can be.
- goat_rodeo_locks: Using a mutex to resolve the race condition goat_rodeo.
- goat_rodeo_guards: Refactoring goat_rodeo_locks to use lock_guard.
- goat_rodeo_atomic: Resolving the race condition using atomic_int rather than mutex
- goat_rodeo_cv: Using condition variables to ensure all cans are deposited before they’re eaten
- parallelism: Sorting a billion numbers using std::sort with std::execution::seq versus std::execution::par.
- undefined_parallel: A program containing a race condition due to non-atomic access to n_transformed
