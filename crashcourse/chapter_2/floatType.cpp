#include <cstdio>
// %f displays a float with decimal digits
// %e displays the same number in scientific notation
// %g format specifier, which selects the more compact of %e or %f
// prefix %lf - long

int main() {
  double an = 6.0221409e23;
  printf("Avogadro's Number: %le %lf %lg\n", an, an, an);
  float hp = 9.75;
  printf("Hogwarts' Platform: %e %f %g\n", hp, hp, hp);
}