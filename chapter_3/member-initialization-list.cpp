#include <cstdio>

struct ClockOfTheLongNow {
  ClockOfTheLongNow() { year = 2019; }

  void add_year() { year++; }

  bool set_year(long year) {
    this->year = year;
    return true;
  }

  long get_year() { return this->year; }

  long year;
};

struct Avout {
  Avout(const char* name, long year_of_apert)
      : name{name}, apert{year_of_apert} {}

  void announce() const {
    printf("My name is %s and my next apert is %d.\n", name, apert.get_year());
  }

  const char* name;
  ClockOfTheLongNow apert;
};

int main() {
  Avout raz{"Erasmas", 3010};
  Avout jad{"Jad", 4000};
  raz.announce();
  jad.announce();
}