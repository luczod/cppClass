#include <cstddef>
#include <cstdio>

void regular_loop() {
  unsigned long maximum = 0;
  unsigned long values[] = {10, 50, 20, 40, 0};

  for (size_t i = 0; i < 5; i++) {
    if (values[i] > maximum) maximum = values[i];
  }
  printf("The maximum value is %lu", maximum);
}

void range_based_loop() {
  unsigned long maximum = 0;
  unsigned long values[] = {10, 50, 20, 40, 0};  // infer length
  // it must match the type
  for (unsigned long value : values) {
    if (value > maximum) maximum = value;
  }
  printf("The maximum value is %lu.", maximum);
}

int main() { range_based_loop(); }