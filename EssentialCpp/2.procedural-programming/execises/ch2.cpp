#include "ch2.hpp"

bool
size_ok(int size)
{
  const int max_size = 93;
  if (size < 0 || size > max_size) {
    cerr << "fibon_seq(): invalid size " << size << endl;
    return false;
  }
  return true;
}

const vector<ElemType>*
fibon_seq(int size)
{
  static vector<ElemType> elems;
  if (!size_ok(size))
    return 0;

  for (int i = elems.size(); i <= size; ++i) {
    if (i == 0 || i == 1)
      elems.push_back(i);
    else
      elems.push_back(elems[i - 1] + elems[i - 2]);
  }
  return &elems;
}

bool
fibon_elem(int n, ElemType& target)
{
  auto elems = fibon_seq(n);
  if (elems) {
    target = elems->at(n);
    return true;
  } else {
    return false;
  }
}