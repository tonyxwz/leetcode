#include "vectemplate.hpp"

int
main()
{
  ess::DummyVector<int> dv { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  for(auto i : dv)
    std::cout << i << std::endl;
  return 0;
}
