#include <iostream>
#include <vector>

using std::vector;

typedef int T;
class Stack
{
public:
  Stack() {

  }
  virtual ~Stack();
  void pop();
  void push(T);
  size_t size() const;
  bool empty() const;
  virtual T& peek();
  virtual const T& peek() const;
  virtual std::ostream& print(std::ostream& os = std::cout);

protected:

private:
};


class 
