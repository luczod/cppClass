// Listing 19-14: Using condition variables to ensure all cans are deposited before they’re eaten
// condition_variable cv
#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>

using namespace std;

void goat_rodeo() {
  mutex m; // 1
  condition_variable cv; // 2
  const size_t iterations{ 1'000'000 };
  int tin_cans_available{};

  auto eat_cans = async(launch::async, [&] {
    unique_lock<mutex> lock{ m }; // 3
    cv.wait(lock, [&] { return tin_cans_available > 0; }); // 4
    for(size_t i{}; i < iterations; i++){
      tin_cans_available--;
    }
  });

  auto deposit_cans = async(launch::async, [&] {
    scoped_lock<mutex> lock{ m };
    for(size_t i{}; i < iterations; i++){
      tin_cans_available++;
    }
    cv.notify_all();
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
