// Listing 19-16: A program containing a race condition due to non-atomic access to
// n_transformed
#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  vector<long> numbers(1'000'000), square(1'000'000); // 1
  iota(numbers.begin(), numbers.end(), 0); // 2 [0,1,2,3,4,5,6,7...]
  size_t n_transformed{}; // 3

  transform(execution::par, numbers.begin(), numbers.end(), square.begin(), // 4
            [&n_transformed](const auto x) {
              ++n_transformed; // 5
              return x * x; // 6
  });

  cout << "n_transformed: " << n_transformed << endl;
}
