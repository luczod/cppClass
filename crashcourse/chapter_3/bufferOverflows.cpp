#include <cstdio>

void buffer_overflow() {
  char lower[] = "abc?e";
  char upper[] = "ABC?E";
  char* upper_ptr = upper;  // Equivalent: &upper[0]

  lower[3] = 'd';      // lower now contains a b c d e
  upper_ptr[3] = 'D';  // upper now contains A B C D E

  char letter_d = lower[3];      // letter_d equals 'd'
  char letter_D = upper_ptr[3];  // letter_D equals 'D'
  printf(" lower: %s\n upper: %s", lower, upper);

  lower[7] = 'g';  // Super bad. You must never do this. buffer overflow
}

void pointer_arithmetic() {
  char lower[] = "abc?e";
  char upper[] = "ABC?E";
  char* upper_ptr = upper;
  // pointer arithmetic
  *(lower + 3) = 'd';
  *(upper_ptr + 3) = 'D';

  char letter_d = *(lower + 4);  // lower decays into a pointer when we add
  char letter_D = *(upper_ptr + 4);
  printf(" lower: %s\n upper: %s", lower, upper);

  *(lower + 7) = 'g';  // writing to some memory that doesn’t belong to lower
}

int main() { pointer_arithmetic(); }