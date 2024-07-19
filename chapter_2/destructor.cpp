#include <cstdio>

/* You declare a class’s destructor with the tilde ~ followed by the name of the
class. the compiler will ensure that each object’s destructor is called as
appropriate. */

struct Earth {
  ~Earth() {  // Earth's destructor
    printf("Making way for hyperspace bypass");
  }
};