#include <functional>
#include <iostream>

template<typename MemberType>
struct MyPair
{
  MemberType a;
  MemberType b;
  MemberType mul() { return a * b; }
};

int
main()
{
  using namespace std::placeholders;
  auto mp = MyPair<int>{2, 4};
  auto bound_member_fn = std::bind(&MyPair<int>::mul, _1);
  std::cout << bound_member_fn(mp) << std::endl;
  return 0;

}
