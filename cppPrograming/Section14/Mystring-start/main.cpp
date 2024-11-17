// Section 14
// Mystring - starting point
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
	Mystring empty;                      // no-args constructor
	Mystring larry("Larry");             // overloaded constructor
	Mystring stooge {larry};            // copy constructor 
	
	empty.display();
	larry.display();
	stooge.display();
	
	return 0;
}

/*
 * Operator Overloading
 * 
 * int a;
 * float b,sum;
 * sum = a + b;
 * 
 * Here, variables “a” and “b” are of types “int” and “float”, 
which are built-in data types. Hence the addition operator ‘+’ can easily 
add the contents of “a” and “b”. This is because the addition operator “+” 
is predefined to add variables of built-in data type only. 
 * 
 * 
 * Now, if the user wants to make the operator “+” add two class objects, 
the user has to redefine the meaning of the “+” operator such that it adds two class objects. 
This is done by using the concept of “Operator overloading”. 
So the main idea behind “Operator overloading” is to use C++ operators 
with class variables or class objects. Redefining the meaning of operators 
really does not change their original meaning; instead, 
they have been given additional meaning along with their existing ones.
 * */
