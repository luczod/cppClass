// Listing 16-18: Constructing a string from cin using input stream buffer iterators
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main() {
  istreambuf_iterator<char> cin_itr{ std::cin.rdbuf() }, end{};

  cout << "What is your name? ";
  const string name{ cin_itr, end };
  cout << "\nGoodbye, " << name;

  return 0;
}
