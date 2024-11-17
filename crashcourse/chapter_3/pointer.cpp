#include <cstdio>
// Addressing Variables (&)
// pointer (*), The format specifier for a pointer is %p.
void pointer() {
  int gettysburg{};  // 0
  printf("gettysburg: %d\n", gettysburg);

  int* gettysburg_address = &gettysburg;
  printf("&gettysburg: %p\n", gettysburg_address);
}

void deref_pointer() {
  int gettysburg{};  // 0
  // pointer
  int* gettysburg_pointer = &gettysburg;
  printf("Value at gettysburg: %d\n", *gettysburg_pointer);
  printf("Gettysburg Address: %p\n", gettysburg_pointer);
  // Dereference Pointers
  *gettysburg_pointer = 17325;
  printf("\rValue at gettysburg: %d\n", *gettysburg_pointer);
  printf("Gettysburg Address: %p\n", gettysburg_pointer);
}

int main() { deref_pointer(); }