// Listing 16-5: A program that counts words from stdin until it encounters an EOF
#include <iostream>
#include <string>

int main() {
  std::string word;
  size_t count{};
  while(std::cin >> word) {
    count++;
  }
  std::cout << "Discovered " << count << " words.\n";
}

/*
In the Windows command line,
you can enter EOF by pressing ctrl-Z and pressing enter. In Linux bash
or in the OS X shell, you press ctrl-D.

cat yoda.txt | ./listing_16_5
 */
