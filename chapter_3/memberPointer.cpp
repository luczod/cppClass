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

int main() {
  ClockOfTheLongNow clock;
  ClockOfTheLongNow* clock_ptr = &clock;
  clock_ptr->set_year(2020);
  printf("Address of clock: %p\n", clock_ptr);
  printf("Value of clock's year: %d", clock_ptr->get_year());
}