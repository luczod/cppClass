#include <cstdio>

// Iterating with an Index
int main()
{
  const int x[]{1, 1, 2, 3, 5, 8}; // array Initialization
  printf("i: x[i]\n");

  for (int i{}; i < 6; i++)
  {
    printf("%d: %d\n", i, x[i]);
  }
}

// Ranged Based for Loops
int ranged()
{
  const int x[]{1, 1, 2, 3, 5, 8};

  for (const auto element : x)
  {
    printf("%d ", element);
  }
}
