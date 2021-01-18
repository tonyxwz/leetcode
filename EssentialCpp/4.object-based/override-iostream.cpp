#include <iostream>
using namespace std;
struct Dummy
{
  int a;
  int b;
  int c;
  // !!!this operator override is bad!!!
  ostream& operator<<(ostream& os) {
    os << a << " " << b << " " << c;
    return os;
  }
};

// it is the best to implement operator<< as a outside function, not a member
// function of `dummy`.
ostream&
operator<<(ostream& os, const Dummy &d)
{
  os << d.a << " " << d.b << " " << d.c;
  return os;
}

istream& operator>>(istream& is, Dummy &d) {

  return is;
}

int
main()
{
  Dummy d{ 3, 2, 1 };
  cout << d << endl;

  // if using the member function override, how confusing is this.
  d << cout << endl;
  return 0;
}
