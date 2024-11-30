// Listing 19-10: An illustration of how disastrous unsynchronized, mutable, shared data
// access can be
#include <future>
#include <iostream>

using namespace std;


void goat_rodeo() {
  const size_t iterations{ 1000000 };
  int tin_cans_available{}; // 1

  auto eat_cans = async(launch::async, [&] { // 2
    for(size_t i{}; i < iterations; i++){
      tin_cans_available--; // 3
    }
  });

  auto deposit_cans = async(launch::async, [&] { // 4
    for(size_t i{}; i < iterations; i++)
      tin_cans_available++; // 5
  });

  eat_cans.get(); // 6
  deposit_cans.get(); // 7 the order doesn’t matter
  cout << "Tin cans: " << tin_cans_available << "\n"; // 8
}

int main() {
  goat_rodeo();
  goat_rodeo();
  goat_rodeo();
}
