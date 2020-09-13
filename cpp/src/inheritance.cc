#include <iostream>

using namespace std;

class Base {
public:
  Base() {}
  virtual void print() { cout << "Base::print" << endl; }

  // not marked as virtual
  void print2() { cout << "Base::print2" << endl; }

  // marked as virtual here but not in derived classes
  virtual void print3() { cout << "Base::print3" << endl; }
};

class Derived : public Base {
public:
  Derived() {}
  virtual void print() override { cout << "Derived::print" << endl; }

  // cannot use override specifier because it is not virtual in Base
  // instead of override, print2 is redefined
  void print2() { cout << "Derived::print" << endl; }

  // not marking print3 as virtual to test later on inheritance
  // automatically considerred as virtual
  // https://stackoverflow.com/a/2964003
  void print3() override { cout << "Derived::print3" << endl; }
};

class Derived2 : public Derived {
public:
  Derived2() {}

  virtual void print() override { cout << "Derived2::print" << endl; }

  void print2() { cout << "Derived2::print2" << endl; }

  // override a function that is virtual in Base but not virtual in
  // Derived2 still successfully called
  void print3() override { cout << "Derived2::print3" << endl; }
};

class Derived3 : public Base {
public:
  Derived3() {}

  void wrapPrint() { this->print(); }

private:
  // polymorphism doesn't have a say on functions like this because if
  // an object of this class is passed using a reference or pointer from
  // outside it won't have the access to a private method.
  virtual void print() override { cout << "Derived3" << endl; }
};

class Base2 {
public:
  Base2() {}
  void print() { cout << "Base2" << endl; }
};

void callPrint(Base &obj) { obj.print(); }

void callPrint2(Base *obj) { obj->print2(); }

void callPrint3(Base &obj) { obj.print3(); }

int main() {
  auto b = Base();
  auto d = Derived();
  auto d2 = Derived2();
  // print
  callPrint(b);
  callPrint(d);
  callPrint(d2);
  // print2 not marked as virtual, always calling base
  callPrint2(&b);
  callPrint2(&d);
  callPrint2(&d2);
  // print3
  callPrint3(b);
  callPrint3(d);
  callPrint3(d2);
  // check `this' pointer
  auto d3 = Derived3();
  d3.wrapPrint();

  return 0;
}
