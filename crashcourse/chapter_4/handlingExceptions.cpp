#include <stdexcept>

int main() {
  try {
    throw std::logic_error{
        "It's not about who wrong "
        "it's not about who right"};
  } catch (std::exception& ex) {
    // Handles std::logic_error as it inherits from std::exception
  }
}
