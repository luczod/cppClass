#include <stdio.h>

#include <cstdio>

int sum(int x, int y) { return x + y; }

int main() {
  int my_num = 4;
  int numy = 4;
  printf("The absolute value of %d is %d.\n", my_num, sum(my_num, numy));
}