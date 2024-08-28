#include <cstdarg>
#include <cstdint>
#include <cstdio>

int sum(size_t n, ...)
{
  va_list args;

  va_start(args, n);

  int result{};

  while (n--)
  {
    auto next_element = va_arg(args, int);
    result += next_element;
  }

  va_end(args);
  return result;
}

// type-safe
template <typename T>
constexpr T sum2(T x)
{
  return x;
}

template <typename T, typename... Args>
constexpr T sum2(T x, Args... args)
{
  return x + sum2(args...);
}

// Fold Expressions
template <typename... T>
constexpr auto sum3(T... args)
{
  return (... + args);
}

int main()
{
  printf("The answer is %d.", sum3(2, 4, 6, 8, 10, 12));
}
