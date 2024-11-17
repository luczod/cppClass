#include <cstdio>

struct Element {
  Element* next{};  // nullptr

  void insert_after(Element* new_element) {
    new_element->next = next;
    next = new_element;  // new_element
  }

  char prefix[2];
  short operating_number;
};

void loop_pointer() {
  Element trooper1, trooper2, trooper3;
  trooper1.prefix[0] = 'T';
  trooper1.prefix[1] = 'K';
  trooper1.operating_number = 421;

  trooper1.insert_after(&trooper2);
  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 2187;

  trooper2.insert_after(&trooper3);
  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 005;

  for (Element* cursor = &trooper1; cursor; cursor = cursor->next) {
    printf("stormtrooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1],
           cursor->operating_number);
  }
}

void loop_reference() {
  int original = 100;
  int& original_ref = original;

  printf("Original: %d\n", original);
  printf("Reference: %d\n\n", original_ref);

  int new_value = 200;
  original_ref = new_value;  // Dereference Pointers: *original_ref = new_value

  printf("Original: %d\n", original);
  printf("New Value: %d\n", new_value);
  printf("Reference: %d\n", original_ref);
}

int main() { loop_reference(); }
