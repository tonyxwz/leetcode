#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class Dog
{
public:
  Dog(const char* name)
  {
    _name = (char*) calloc(strlen(name)+1, sizeof(char));
    strncpy(_name, name, strlen(name));
    cout << sizeof(char) * strlen(name) << endl;
  }
  virtual ~Dog()
  {
    cout << "Dog " << _name << " destroyed" << endl;
    free(_name);
  }

protected:
  char* _name = NULL;
};

class YellowDog : public Dog
{
public:
  YellowDog(const char* name, int shade)
    : Dog(name)
    , _shade(shade)
  {}
  ~YellowDog() { cout << "Yellow Dog " << _name << " destroyed" << endl; }

private:
  int _shade;
};

int
main()
{
  Dog* tony = new Dog("Tony Xing");
  Dog* jack = new YellowDog("Jack", 12);

  delete tony;
  delete jack;
}
