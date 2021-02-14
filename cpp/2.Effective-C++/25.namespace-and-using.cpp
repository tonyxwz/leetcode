#include <iostream>

using namespace std; // using directive: bring all members of a namespace into
                     // current scope
using std::cout; // using declaration: 1. bring a specific namespace member into
                 // scope
                 //                    2. bring a member from base class to
                 //                       current class's scope

class B
{
public:
  void f(int b);
};

class D : private B
{
public:
  void g()
  {
    using namespace std; // local scope, ok
    using std::cout;     // local scope, ok
  }
  using B::f; // class scope, ok
  /* using std::cout;     // illegal */
  /* using namespace std; // illegal */
};

/* using B::f; // illegal */

// example 2
class D2 : public B // public inheritance
{
public:
  using B::f;
  void f();
};

int
main()
{
  D2 d;
  // error, B::f is a non-virtual function. C++ name resolution will stop
  // searching upwards once it finds D2::f. In order to use B::f as a public
  // function in D2, we need using declaration. Or call B::f explicitly.
  d.B::f(8);
  d.f(8);
  return 0;
}

// anonymous namespace

// static global functions are only visible in the source file they are defined
// in.
static void
t(){};

namespace {
void
t(){};

void
k()
{
  t(); // calls the t in current namespace.
}
}

