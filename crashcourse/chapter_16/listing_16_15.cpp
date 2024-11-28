// Listing 16-15: A program that reads the text file numbers.txt
// and prints its maximum integer
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

int main() {
  ifstream file{ "numbers.txt" };

  auto maximum = numeric_limits<int>::min();
  int value;

  while(file >> value){
    maximum = maximum < value ? value : maximum;
  }

  cout << "Maximum found was " << maximum << endl;
}

// reads the text file and prints its maximum integer
