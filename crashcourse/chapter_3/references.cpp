#include <cstdio>

struct ClockOfTheLongNow {
  ClockOfTheLongNow() { year = 2019; }

  void add_year() { year++; }

  bool set_year(int new_year) {
    year = new_year;
    return true;
  }

  int get_year() { return year; }

  int year;
};

// references(&)
void add_year(ClockOfTheLongNow& clock) {
  clock.set_year(clock.get_year() + 1);  // No deref operator needed
}

void ref() {
  ClockOfTheLongNow clock;
  printf("The year is %d.\n", clock.get_year());
  add_year(clock);  // Clock is implicitly passed by reference!
  printf("The year is %d.\n", clock.get_year());
}

int main() { ref(); };