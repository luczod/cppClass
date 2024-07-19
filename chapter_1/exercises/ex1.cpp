#include <cstdio>

int sum(int x) {
  if (x < 0) {
    return x * -1;
  } else {
    return x;
  }
}

int main() {
  int my_num = 4;
  printf("The absolute value of %d is %d.\n", my_num, sum(my_num));
}