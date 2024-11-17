#include <cstdio>
#include <cstdint>

/*
accepts two parameters, argc and argv.
The first argument, argc, is a non-negative number
corresponding to the number of elements in argv.
 */

int main(int argc, char **argv)
{
  printf("Arguments: %d\n", argc);

  for (size_t i{}; i < argc; i++)
  {
    printf("%zd: %s\n", i, argv[i]);
  }
}

// 0 : path
