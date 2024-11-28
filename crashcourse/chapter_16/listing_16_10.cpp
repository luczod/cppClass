// Listing 16-10: A program illustrating how to implement
// an input operator ">>" for a deque
#include <deque>
#include <iostream>

using namespace std;

template <typename T>
istream& operator>>(istream& s, deque<T>& t) {
  T element;
  while(s >> element)
    t.emplace_back(move(element));
  return s;
}

int main() {
  cout << "Give me numbers: ";
  deque<int> numbers;
  cin >> numbers;
  int sum{};
  cout << "Cumulative sum:\n";
  for(const auto& element : numbers) {
    sum += element;
    cout << sum << "\n";
  }
}

/* As with the output operator, the input operator typically returns u the
same stream it receives v. However, unlike with the output operator, the
YourType reference will generally not be const, because you’ll want to modify
the corresponding object using input from the stream */
