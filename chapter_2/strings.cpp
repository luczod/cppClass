#include <cstdio>
// Declare string literals by enclosing text in quotation marks ("")
char english[] = "A book holds a house of gold.";
// \u + digits UNICODE
char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";

int main() {
  // char house[] = "a house of gold.";
  // Consecutive string literals get concatenated together
  char house[] =
      "a "
      "house "
      "of "
      "gold.";
  printf("A book holds %s\n ", house);
}