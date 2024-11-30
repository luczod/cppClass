// Listing 19-11: Using a mutex to resolve the race condition in Listing 19-10
#include <future>
#include <iostream>
#include <mutex>

using namespace std;

void goat_rodeo() {
  const size_t iterations{ 1'000'000 };
  int tin_cans_available{};
  mutex tin_can_mutex; // 1

  auto eat_cans = async(launch::async, [&] {
    for(size_t i; i < iterations; i++) {
      tin_can_mutex.lock(); // 2
      tin_cans_available--;
      tin_can_mutex.unlock(); // 3
    }
  });

  auto deposit_cans = async(launch::async, [&] {
    for(size_t i; i < iterations; i++) {
      tin_can_mutex.lock(); // 4
      tin_cans_available++;
      tin_can_mutex.unlock(); // 5
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
