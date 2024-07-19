#include <cstdio>

// class invariant
struct ClockOfTheLongNow {
  ClockOfTheLongNow(int year_in) {
    if (!set_year(year_in)) {
      year = 2019;
    }
  }
  void add_year() { year++; }

  bool set_year(int new_year) {
    if (new_year < 2019) return false;
    year = new_year;
    return true;
  }

  int get_year() { return year; }

 private:
  int year;
};

// The class keyword, which declares members private by defaulf
class ClockOfTheLongTwo {
  int year;

 public:
  void add_year() { year++; }
  bool set_year(int new_year) {
    if (new_year < 2019) return false;
    year = new_year;
    return true;
  }
  int get_year() { return year; }
};

int main() {
  // ClockOfTheLongNow clock;
  // clock.year = 2017;
  // clock.set_year(2020);
  ClockOfTheLongNow clock{2020};

  clock.add_year();
  printf("year: %d\n", clock.get_year());
  clock.add_year();
  printf("year: %d\n", clock.get_year());
}