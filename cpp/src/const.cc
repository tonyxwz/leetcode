#include <iostream>

using namespace std;

class Plant
{
  private:
  const int C;
  int M;
  public:
  Plant()
  : C(1)
  {
  };
  
  // use 'const' function whenever possible
  void printC() const { cout << C << endl;}

  // p.s. this is the reason of this pointer, to distinguish M from argument.
  // a const instance can only use const functions.
  // this pointer in a method call of const instance is also const, so no modification is allowed.
  void changeM(int M) {this->M = M;}
};


int main() {
  auto p = Plant();
  const auto c = Plant();
  // error
  // c.changeM(4);
  p.changeM(5);
}