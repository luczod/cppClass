#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <iostream>

// The boost::scoped_ptr is an RAII wrapper

struct DeadMenOfDunharrow
{
  DeadMenOfDunharrow(const char *m = "") : message{m}
  {
    oaths_to_fulfill++;
  }

  ~DeadMenOfDunharrow()
  {
    oaths_to_fulfill--;
  }
  const char *message;
  static int oaths_to_fulfill;
};

int DeadMenOfDunharrow::oaths_to_fulfill{};
using ScopedOathbreakers = boost::scoped_ptr<DeadMenOfDunharrow>;

TEST_CASE("ScopedPtr is an RAII wrapper.")
{
  REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 0);

  ScopedOathbreakers aragorn{new DeadMenOfDunharrow{}};

  REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  {
    ScopedOathbreakers legolas{new DeadMenOfDunharrow{}};

    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
  }

  REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
}
