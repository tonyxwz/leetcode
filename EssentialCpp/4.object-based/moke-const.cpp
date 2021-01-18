#include <iostream>

class Thing
{
private:
  int a;
  mutable int b;
  int c;

public:
  Thing(int a, int b, int c)
    : a(a)
    , b(b)
    , c(c)
  {}
  void changea(int newa) const
  {
    const_cast<Thing*>(this)->a = newa;
    // a = newa;
    b = newa;
  }

  void print()
  {
    std::cout << a << std::endl;
    std::cout << b << std::endl;
  }
};

void
someFunc(const Thing& t)
{
  t.changea(4);
  t.print();
}

int
main()
{
  Thing x(1, 2, 3);
  someFunc(x);
  return 0;
}