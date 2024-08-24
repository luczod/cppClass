#include <cstdio>
/* The global namespace contains all the symbols that you can access without adding
any namespace qualifiers. */

namespace BroopKidron13::Shaltanac
{
  enum class Color
  {
    Mauve,
    Pink,
    Russet
  };
}

int main()
{
  using BroopKidron13::Shaltanac::Color; // Directives
  // const auto shaltanac_grass{BroopKidron13::Shaltanac::Color::Russet};
  const auto shaltanac_grass = Color::Russet;

  if (shaltanac_grass == BroopKidron13::Shaltanac::Color::Russet)
  {
    printf("The other Shaltanac's joopleberry shrub is always "
           "a more mauvey shade of pinky russet.");
  }
}
