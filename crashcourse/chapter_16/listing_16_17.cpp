// Listing 16-17: Writing the message Hi to stdout using the ostreambuf_iterator class
#include <iostream>
#include <iterator>

using namespace std;

int main() {
  ostreambuf_iterator<char> itr{ cout };
  *itr = 'H';
  ++itr;
  *itr = 'i';
}
