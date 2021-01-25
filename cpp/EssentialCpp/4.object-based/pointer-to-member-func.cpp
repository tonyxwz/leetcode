#include <algorithm>
#include <iostream>
#include <vector>

class OmniSeq
{
public:
  // define a pointer to a member function
  // Note the scope specifier
  OmniSeq() = default;
  typedef void (OmniSeq::*pPrintFunc)(int);

  enum FUNCS
  {
    nullfunc,
    square,
    x2,
    fibb
  };

  void printSquare(int n)
  {
    for (int i = 0; i < n; ++i)
      std::cout << i * i << " ";
    std::cout << std::endl;
  }

  void print_x2(int n)
  {
    for (int i = 0; i < n; ++i)
      std::cout << i * 2 << " ";
    std::cout << std::endl;
  }

  void printFibb(int n)
  {
    int a = 0;
    int b = 1;
    std::cout << a << " " << b << " ";
    for (int i = 3; i < n; ++i) {
      a = a + b;
      b = a;
      std::cout << a << " ";
    }
    std::cout << std::endl;
  }

  void setSeq(FUNCS n) { _pfunc = _func_array[n]; }

  void operator()(int n)
  {
    if (_pfunc)
      // !! important, pointer to class member function must be invoked via an
      // object of that class. even if it is inside of a class method.
      //
      // object.*_pfunc, objectptr->*_pfunc.
      //
      // obvious reason, class method syntax is fake. you still need the calling
      // object anyway. member function have only one copy in run time, multiple
      // objects of the same class share the same copy of the member method (via
      // pointers). the first argument to the class method is always `self`.
      // (seems that python is right).
      (this->*_pfunc)(n);
  }

private:
  static constexpr pPrintFunc _func_array[] = { nullptr,
                                                &OmniSeq::printSquare,
                                                &OmniSeq::print_x2,
                                                &OmniSeq::printFibb };
  pPrintFunc _pfunc = nullptr;
};

int
main()
{
  using namespace std;
  OmniSeq ns;
  const int pos = 8;
  ns.setSeq(OmniSeq::fibb);
  ns(pos);
  return 0;
}
