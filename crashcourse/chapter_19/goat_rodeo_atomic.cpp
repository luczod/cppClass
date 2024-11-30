// Listing 19-13: Resolving the race condition using atomic_int rather than mutex
#include <atomic>
#include <future>
#include <iostream>

using namespace std;

void goat_rodeo() {
  const size_t iterations{ 1'000'000 };
  atomic_int tin_cans_available{}; // 1

  auto eat_cans = async(launch::async, [&] {
    for(size_t i{}; i < iterations; i++){
      tin_cans_available--; // 2
    }
  });

  auto deposit_cans = async(launch::async, [&] {
    for(size_t i{}; i < iterations; i++){
      tin_cans_available++; // 3
    }
  });

  eat_cans.get();
  deposit_cans.get();
  cout << "Tin cans: " << tin_cans_available << "\n";
}

int main() {
  goat_rodeo();
  goat_rodeo();
  goat_rodeo();
}

/* Because the decrement and increment operators are atomic, the race condition remains solved.
 In general, using atomic operations will be much faster than acquiring a mutex. */
