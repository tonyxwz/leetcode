#include "Vec.hpp"
#include <algorithm>
#include <iostream>

namespace ess {
// constructor
Vec::Vec() : Vec(0) {}

// constructor
Vec::Vec(std::size_t size)
    : _max_size(size), _data(_max_size ? new int[_max_size]() : nullptr) {
  std::cout << "created array of size " << _max_size << std::endl;
}

// constructor
Vec::Vec(std::size_t size, const int init) : Vec(size) {
  for (int i = 0; i < _max_size; ++i) {
    _data[i] = init;
  }
}

// destrutor
Vec::~Vec() {
  std::cout << "freed" << std::endl;
  delete[] this->_data;
}

// copy constructor
Vec::Vec(const Vec &other) : Vec(other._max_size) {
  for (int i = 0; i < _max_size; i++)
    _data[i] = other[i];
}

/* ************************
 * copy assignment operator
 * Copy and Swap idiom
 * this is a nice solution because the compiler does the copying in the argument
 * passing, then we just swap the newly copied object with ours.
 */
Vec &Vec::operator=(Vec other) {
  swap(*this, other);
  return *this;
}
// without the copy and swap idiom
// benefit (seemingly), when assign to self, not handled at all. the copy and
// swap idiom still have to make a copy of self the assign to self, then destroy
// the copied object.
/*
Vec &Vec::operator=(const Vec &other) {
  if (this == &other)
    return *this;  // avoid self assignment

  int* _data_original = _data;
  _data = new int[other._max_size](); // exception possible
  _max_size = other._max_size;
  for(int i = 0; i < _max_size; ++i)
    _data[i] = other._data[i];
  // free only if new operator succeeds, exception safe return *this;
  delete [] _data_original;
}
*/

int &Vec::operator[](std::size_t i) { return _data[i]; }

const int &Vec::operator[](std::size_t i) const { return _data[i]; }

// finding this function through ADL
// when making an unqualified call to swap, the arguments are Vec which are
// defined in namespace ess, ADL will first try to find the swap function
// defined in this namespace.
void swap(Vec &first, Vec &second) {
  // not necessary this time because swaping int and pointer are defined by
  // std::swap. but this is good practice.
  using std::swap;
  swap(first._max_size, second._max_size);
  swap(first._data, second._data);
}

Vec::iterator Vec::begin() { return Vec::iterator(this->_data); }
Vec::iterator Vec::end() { return Vec::iterator(this->_data + _max_size); }

}; // namespace ess
