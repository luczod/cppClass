#include <cstdio>
/*
There is no format specifier for bool, but you can use the int format
specifier %d within printf to yield a 1 for true and a 0 for false.
*/

int main() {
  bool b1 = true;   // b1 is true
  bool b2 = false;  // b2 is false
  printf("%d %d\n", b1, b2);
}