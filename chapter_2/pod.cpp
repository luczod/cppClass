#include <cstdio>

// heterogeneous array
struct Book {
  char name[256];
  int year;
  int pages;
  bool hardcover;
};

void pod() {
  Book neuromancer;
  neuromancer.pages = 271;
  printf("Neuromancer has %d pages.", neuromancer.pages);
}

// The union is a cousin of the POD
union Variant {
  char string[10];
  int integer;
  double floating_point;
};

// You should avoid using unions
void unionVar() {
  Variant var;
  var.integer = 42;
  printf("The ultimate answer: %d\n", var.integer);
  var.floating_point = 2.7182818284;
  printf("Euler's number e: %f\n", var.floating_point);
  printf("A dumpster fire: %d\n", var.integer);  // double > int
}

int main() { unionVar(); }