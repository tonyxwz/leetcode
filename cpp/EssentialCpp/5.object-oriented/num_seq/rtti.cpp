#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

using namespace std;

class Base
{
public:
  virtual void print() const
  {
    int status;
    cout << abi::__cxa_demangle(typeid(*this).name(), 0, 0, &status) << endl;
    cout << "x = " << x << ", y = " << y << endl;
  }

protected:
  Base() = delete;
  Base(int x, int y)
    : x(x)
    , y(y)
  {}
  virtual ~Base(){};

private:
  int x;
  int y;
};

class Derived : public Base
{
public:
  Derived(int x, int y, int z)
    : Base(x, y)
    , z(z)
  {}
  void print() const override
  {
    Base::print();
    cout << "z = " << z << endl;
  }

private:
  int z;
};

int
main()
{
  Derived d(1, 2, 3);
  Base* pb = &d;
  d.Derived::print(); // ok
  /* pb->Derived::print(); // error */
  // ok but dangerous because static cast doesn't check the actual type
  static_cast<Derived*>(pb)->Derived::print();
  // better, dynamic-cast will return 0 if the conversion fails
  if (Derived *tmp = dynamic_cast<Derived*>(pb))
    tmp->print();

  pb->print(); // ok
  return 0;
}
