#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
  // ":" member initialization
  SimpleString(size_t max_size) : max_size{max_size}, length{} {
    if (max_size == 0) {
      throw std::runtime_error{"Max size must be at least 1."};
    }

    buffer = new char[max_size];
    buffer[0] = 0;
  }
  // the copy constructor
  SimpleString(const SimpleString& other)
      : max_size{other.max_size},
        buffer{new char[other.max_size]},
        length{other.length} {
    // copies the contents pointed to by other
    std::strncpy(buffer, other.buffer, max_size);
  }
  // copy assignment
  SimpleString& operator=(const SimpleString& other) {
    if (this == &other) return *this;

    const auto new_buffer = new char[other.max_size];
    delete[] buffer;
    buffer = new_buffer;
    length = other.length;
    max_size = other.max_size;
    strcpy_s(buffer, max_size, other.buffer);

    return *this;
  }

  // destructor
  ~SimpleString() { delete[] buffer; }

  void print(const char* tag) const {
    printf("tag %s\nbuffer: %s\n", tag, buffer);
  }

  bool append_line(const char* x) {
    const auto x_len = strlen(x);

    if (x_len + length + 2 > max_size) return false;
    std::strncpy(buffer + length, x, max_size - length);

    length += x_len;
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }

 private:
  size_t max_size;
  char* buffer;
  size_t length;
};

void foo(SimpleString x) { x.append_line("This change is lost."); }

void sample_copy() {
  SimpleString a{50};
  a.append_line("We apologize for the");
  SimpleString a_copy{a};
  a.append_line("inconvenience.");
  a_copy.append_line("incontinence.");
  a.print("a");
  a_copy.print("a_copy");
}

int main() {
  SimpleString a{20};
  foo(a);  // Invokes copy constructor
  a.print("Still empty");
}
