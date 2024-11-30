// Listing 19-15: Sorting a billion numbers using std::sort with std::execution::seq versus
// std::execution::par. (Results are from a Windows 10 x64 machine with two Intel Xeon
// E5-2620 v3 processors.)
#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

struct Stopwatch {
  explicit Stopwatch(chrono::nanoseconds& result)
      : result{ result }
      , start{ chrono::high_resolution_clock::now() } {}

  ~Stopwatch(){
    result = chrono::high_resolution_clock::now() - start;
  }

  private:
    chrono::nanoseconds& result;
    const chrono::time_point<chrono::high_resolution_clock> start;
};

vector<long> make_random_vector() { // 1
  vector<long> numbers(1'000'000'000);
  iota(numbers.begin(), numbers.end(), 0);
  mt19937_64 urng{ 121216 };
  shuffle(numbers.begin(), numbers.end(), urng);

  return numbers;
}

int main() {
  cout << "Constructing random vectors...";
  auto numbers_a = make_random_vector(); // 2
  auto numbers_b{ numbers_a }; // 3

  chrono::nanoseconds time_to_sort;

  cout << " " << numbers_a.size() << " elements.\n";
  cout << "Sorting with execution::seq...";
  {
    Stopwatch stopwatch{ time_to_sort }; // 150 seconds
    //  sort with a sequential execution policy
    sort(execution::seq, numbers_a.begin(), numbers_a.end()); // 4
  }
  cout << " took " << time_to_sort.count() / 1.0E9 << " sec.\n";

  cout << "Sorting with execution::par...";
  {
    Stopwatch stopwatch{ time_to_sort }; // 18 seconds
    // sort with a parallel execution policy
    sort(execution::par, numbers_b.begin(), numbers_b.end()); // 5
  }
  cout << " took " << time_to_sort.count() / 1.0E9 << " sec.\n";
}

/* parallel algorithms aren’t magic. A red flag is any algorithm
 that passes a function object to the algorithm. */
