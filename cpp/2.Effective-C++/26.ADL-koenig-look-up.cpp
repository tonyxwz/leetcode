#include <iostream>

using namespace std;

// example 1: a simple ADL case
namespace A {

struct X
{};

void g(X)
{
  cout << "calling A::g\n";
}
}

// example 2: ADL only apply to namespace scope
class C
{
public:
  struct Y
  {};
  static void h(Y) { cout << "calling C::h\n"; }
};

// example 3: class scope has higher priority than ADL. Or class members are
// more tightly bound than any other function.
// Including the member functions from parent classes
class P
{
public:
  void g(A::X) { cout << "calling P::g\n"; }
  void j()
  {
    A::X x;
    g(x); // will use P::g, unless there's no P::g found by compiler
  }
};

int
main()
{
  // 1
  A::X x;
  g(x); // compiler will search in current scope, global scope and the scope
        // where X come from because g has a parameter of type X

  // 2
  C::Y y;
  C::h(y); // C:: qualification is required, koenig lookup only applies to
           // namespaces, not class scope. This is valid for class member
           // functions. However, it is possible to define inline friend
           // functions inside class scope, in that case, ADL will work.

  // 3
  P p;
  p.j();
  return 0;
}
