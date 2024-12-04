#include <iostream>

using namespace std;

void example_one() {
  // Create an int variable
  int myInt;
  
  int myNumbers[4] = {25, 50, 75, 100};
  
  // Get the memory size in bytes of an int
  printf("%lu\n", sizeof(myInt));
  
  // Get the size of the myNumbers array
  printf("%lu\n", sizeof(myNumbers));
  
  // Get the value of the first element in myNumbers
  // myNumbers is a pointer to the first element in myNumbers
  printf("%d\n", *myNumbers);
  
  // Get the value of the second element in myNumbers
  printf("%d\n", *(myNumbers + 1));
  
   
  // Shifts the value to left by the number of bits specified by the right operand.
  // (a<<b) is equivalent to multiplying a with 2^b (2 raised to power b). 
  printf("%d\n", *myNumbers << 3);
  
  // Shifts the value to right by the number of bits specified by the right operand.
  // (a>>b)  is equivalent to dividing a with 2^b (2 raised to power b). 
  printf("%d\n", *myNumbers >> 2);

  // The left-shift and right-shift operators should not be used for negative numbers. 
}

void example_two() {
    int scores[] {100, 95, 89};
    
    cout << "Value of scores: " << scores << endl;     
    
    int *score_ptr {scores};
    cout << "Value of score_ptr: " << score_ptr << endl;
    
    cout << "\nArray subscript notation -------------------------" << endl;
    cout << scores[0] << endl;
    cout << scores[1] << endl;
    cout << scores[2] << endl;
    
    cout << "\nPointer subscript notation -------------------------" << endl;
    cout << score_ptr[0] << endl;
    cout << score_ptr[1] << endl;
    cout << score_ptr[2] << endl;
    
    cout << "\nPointer offset notation-------------------------" << endl;
    cout << *score_ptr << endl;
    cout << *(score_ptr + 1) << endl;
    cout << *(score_ptr +2) << endl;
    
    cout << "\nArray offset notation-------------------------" << endl;
    cout << *scores << endl;
    cout << *(scores + 1) << endl;
    cout << *(scores +2) << endl;
    
    cout << endl;

}

int main() {
    example_one();
    example_two();
  
    return 0;
}

