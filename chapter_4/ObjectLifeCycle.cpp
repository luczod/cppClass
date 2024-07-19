#include <cstdio>

struct Tracer {
  // construction
  Tracer(const char* nameu) : name{name} { printf("%s constructed.\n", name); }
  // destruction
  ~Tracer() { printf("%s destructed.\n", name); }

 private:
  const char* const name;
};

static Tracer t1{"Static variable"};
thread_local Tracer t2{"Thread-local variable"};

int main() {
  printf("A\n");
  Tracer t3{"Automatic variable"};
  printf("B\n");
  const auto* t4 = new Tracer{"Dynamic variable"};
  printf("C\n");
}