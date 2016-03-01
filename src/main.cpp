#include <cassert>
#include "simulation.h"

//Just for testing the C++ code
int main()
{
  const auto result = do_simulation();
  assert(!result.empty());
  assert(1==2);
}
