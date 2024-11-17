#include <cstdio>

int array_1[]{1, 2, 3};   // Array of length 3; 1, 2, 3
int array_2[5]{};         // Array of length 5; 0, 0, 0, 0, 0
int array_3[5]{1, 2, 3};  // Array of length 5; 1, 2, 3, 0, 0
int array_4[5];           // Array of length 5; uninitialized values

// Number of Elements in an Array
short array[] = {104, 105, 32, 98, 105, 108, 108, 0};
size_t n_elements = sizeof(array) / sizeof(short);

// safely obtain the number of elements using the
// std::size function available in the<iterator> header.

int main() {
  int arr[] = {1, 2, 3, 4};
  printf("The third element is %d.\n", arr[2]);
  arr[2] = 100;
  printf("The third element is %d.\n", arr[2]);
}