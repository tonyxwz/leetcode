#include <cstdio>
#include <iostream>
#include <string>

class A
{
public:
  A(std::string name) // convert string into A
  : name_(name)
  {}
  operator std::string()
    const // convert A into string (BAD PRATICE two-way conversion)
  {
    return name_;
  }

private:
  std::string name_;
};

int
main()
{
  using namespace std;
  string s("hhhh");
  A a = s;
  printf("a is %s", string(a));
  return 0;
}
