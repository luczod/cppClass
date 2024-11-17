#include <cstdio>

struct Element {
  Element* next{};  // nullptr

  void insert_after(Element* new_element) {
    // this Pointers
    new_element->next = this->next;
    this->next = new_element;  // new_element
  }

  char prefix[2];
  short operating_number;
};

struct ClockOfTheLongNow {
  ClockOfTheLongNow() { year = 2019; }

  void add_year() { year++; }
  // before: new_year
  bool set_year(int year) {
    this->year = year;
    return true;
  }

  int get_year() { return this->year; }

  int year;
};
