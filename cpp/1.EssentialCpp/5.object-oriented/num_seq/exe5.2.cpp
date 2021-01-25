#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// concrete base class
template<typename elemType>
class Stack
{
public:
  Stack(int capacity = 0)
    : _top(0)
  {
    if (capacity)
      _stack.reserve(capacity);
  }
  int size() const { return _stack.size(); }
  bool empty() const { return !_top; }
  bool full() const { return _top >= _stack.max_size(); }
  int top() const { return _top; }

  void print(ostream& os = cout) const;

  bool pop(elemType& elem);
  bool push(elemType elem);                           // use move
  virtual bool peek(int, elemType&) { return false; } // disabled

protected:
  int _top;
  vector<elemType> _stack;
};

template<typename elemType>
bool
Stack<elemType>::pop(elemType& target)
{
  if (empty())
    return false;
  target = _stack[--_top]; // no problem here. becuase we are sure that target
                           // refers to some object out side of the class
  _stack.pop_back();
  return true;
}

template<typename elemType>
bool
Stack<elemType>::push(elemType target)
{
  if (full())
    return false;
  _stack.push_back(std::move(target));
  ++_top;
  return true;
}

template<typename elemType>
void
Stack<elemType>::print(ostream& os) const
{
  auto rit = _stack.rbegin(), rend = _stack.rend();
  while (rit != rend)
    os << *rit++ << "\t";
  os << endl;
}


template<typename elemType>
ostream&
operator<<(ostream& os, Stack<elemType>& st)
{
  st.print(os);
  return os;
}

template<typename elemType>
class Peekback_Stack : public Stack<elemType>
{
  bool peek(int index, elemType& target) override
  {
    // this is surprising, but inherited template class needs the this pointer
    // to be specific about inherited members
    if (index < 0 || index > this->_top)
      return 0;
    target = this->_stack[index];
    return true;
  }
};

template<typename elemType>
void
peek(Stack<elemType>& st, int index)
{
  cout << endl;
  string t;
  if (st.peek(index, t))
    cout << "peek: " << t;
  else
    cout << "peek failed!";
  cout << endl;
}

int
main()
{
  Stack<string> st;
  string str;
  while (cin >> str && !st.full())
    st.push(str);
  cout << '\n' << "About to call peek() with Stack" << endl;
  peek(st, st.top() - 1);
  cout << st;
  Peekback_Stack<string> pst;
  while (!st.empty()) {
    string t;
    if (st.pop(t))
      pst.push(t);
  }
  cout << "About to call peek() with Peekback_Stack" << endl;
  peek(pst, pst.top() - 1);
  cout << pst;
}
