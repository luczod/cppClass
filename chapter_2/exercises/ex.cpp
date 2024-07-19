#include <cstdio>

enum class Operation { Add, Subtract, Multiply, Divide };

// heterogeneous array
struct Calculator {
  Calculator(int x, int y) {
    a = x;
    b = y;
  }

  int addition() { return a + b; }
  int subtraction() { return a - b; }
  int multiplication() { return a * b; }
  float division() { return (float)a / (float)b; }

 private:
  int a;
  int b;
};

int main() {
  Calculator calc{5, 2};
  printf("add: %d", calc.addition());
  printf("\rsub: %d", calc.subtraction());
  printf("\nmult: %d", calc.multiplication());
  printf("\rdiv: %g", calc.division());
}