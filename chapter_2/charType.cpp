#include <cstdio>
// printf format specifier for char is %c
int main() {
  char x = 'M';
  wchar_t y = L'Z';
  printf("Windows binaries start with %c%lc.\n", x, y);
}