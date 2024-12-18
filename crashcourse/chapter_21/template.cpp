// Listing 21-1: A framework for investigating program termination and cleanup facilities
#include <cstdio>
#include <iostream>
#include <string>

struct Tracer {
  Tracer(std::string name_in)
      : name{ std::move(name_in) } {
    std::cout << name << " constructed.\n";
  }
  ~Tracer() {
    std::cout << name << " destructed.\n";
  }

  private:
  std::string name;
};

Tracer static_tracer{ "static Tracer" };

void run() {
  std::cout << "Entering run()\n";
  // ...
  std::cout << "Exiting run()\n";
}

int main() {
  std::cout << "Entering main()\n";
  Tracer local_tracer{ "local Tracer" };
  thread_local Tracer thread_local_tracer{ "thread_local Tracer" };
  const auto* dynamic_tracer = new Tracer{ "dynamic Tracer" };
  run();
  delete dynamic_tracer;
  std::cout << "Exiting main()\n";
}
