#include <iostream>
#include <functional>

struct Foo
{
    int _x;

    explicit Foo(int x) : _x(x) { }

    // copy constructor, get called when bind by copy
    Foo(Foo const& f) : _x(f._x)
    {
        std::cout << "Foo(Foo const&)" << std::endl;
    }

    int get(int n) { return _x + n; }
};

int main()
{
  using namespace std::placeholders;
   Foo foo1(42);

   std::cout << "=== FIRST CALL ===" << std::endl;
   auto L1 = std::bind(&Foo::get, foo1, 3);
   foo1._x = 1729;
   std::cout << L1() << std::endl; // Prints 45

   Foo foo2(42);

   std::cout << "=== SECOND CALL ===" << std::endl;
   auto L2 = std::bind(&Foo::get, &foo2, 3);
   foo2._x = 1729;
   std::cout << L2() << std::endl; // Prints 1732
}
