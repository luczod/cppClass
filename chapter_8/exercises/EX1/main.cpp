#include <iostream>
#include "fibonacci_iterator.hpp"

int main()
{
  for (const auto i : FibonacciRange{5000})
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
