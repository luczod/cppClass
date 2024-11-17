#include <cstdio>
/*
A signed variable can be positive, negative, or zero, and an unsigned variable
must be non-negative.
*/

void non_decimal_to_int() {
  unsigned short a = 0b10101010;
  printf("%hu\n", a);
  int b = 0123;
  printf("%d\n", b);
  unsigned long long d = 0xFFFFFFFFFFFFFFFF;
  printf("%llu\n", d);
}

void raw_numbers() {
  unsigned int a = 3669732608;
  printf("Yabba %x!\n", a);  // hexadecimal
  unsigned int b = 69;
  printf("There are %u,%o leaves here.\n", b, b);  // unsigned int and octal
}

int main() { raw_numbers(); }