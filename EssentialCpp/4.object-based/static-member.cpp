#include <algorithm>
#include <iostream>
#include <vector>

class SomeClass
{

private:
  int a;
  int b;

public:
  inline static std::vector<int> _elems;
  static std::vector<int> _elems2;

  SomeClass(int a, int b)
    : a(a)
    , b(b)
  {}

  static bool a_static_func(int a)
  {
    return std::find(_elems2.begin(), _elems2.end(), a) != _elems2.end();
  }

  void get_ab() const { std::cout << a << " " << b << std::endl; }
};

std::vector<int> SomeClass::_elems2 = std::vector<int>(8, 100);

int
main()
{
  SomeClass s{ 4, 3 };
  SomeClass::_elems.push_back(65);

  if(SomeClass::a_static_func(100))
    for(const auto &e: SomeClass::_elems2)
      std::cout << e << " " << std::endl;
  for (const auto& e : SomeClass::_elems)
    std::cout << e << std::endl;
  return 0;
}
