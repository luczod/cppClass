#include <cstddef>
#include <cstdio>
#include <type_traits>

/* concepts aren’t yet officially part of the C++ standard,
GCC version 6.0 or later  */
template <typename T>
concept bool Averageable() {
  return std::is_default_constructible<T>::value u && requires(T a, T b) {
    { a += b }
    ->T;
    {
      a / size_t { 1 }
    }
    ->T;
  };
}

template <Averageable T>
T mean(T* values, size_t length) {
  T result{};
  for (size_t i{}; i < length; i++) {
    result += values[i];
  }
  return result / length;
}
