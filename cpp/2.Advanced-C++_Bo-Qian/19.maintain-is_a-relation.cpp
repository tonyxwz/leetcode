#include <iostream>
#include <string>
using namespace std;

class Dog
{
public:
  virtual void bark(string msg = "just a")
  {
    cout << "I am " << msg << " dog" << endl;
  }
  virtual ~Dog() {}
};
class Yellowdog: public Dog
{
public:
  virtual void bark(string msg = "yellow")
  {
    cout << "I am " << msg << " dog" << endl;
  }
  virtual ~Yellowdog() {}
};

int main() {
  Yellowdog* yd = new Yellowdog();
  yd->bark();
  Dog* d = yd;
  d->bark();
  delete yd;
  return 0;
}
