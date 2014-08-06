#include <cassert>
#include "reciprocal.hpp"
double reciprocal(int i)
{
   // i should not be zero
   assert(i != 0);
   return 1.0/i;
}
