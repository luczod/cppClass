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

void join_strings() {
  SimpleString string{115};  // max_length

  string.append_line("Starbuck, whaddya hear?");
  string.append_line("Nothin' but the rain.");
  string.print("A: ");
  string.append_line("Grab your gun and bring the cat in.");
  string.append_line("Aye-aye sir, coming home.");
  string.print("B: ");

  if (!string.append_line("Galactica!")) {
    printf("String was not big enough to append another message.");
  }
}

int main() { join_strings(); }
