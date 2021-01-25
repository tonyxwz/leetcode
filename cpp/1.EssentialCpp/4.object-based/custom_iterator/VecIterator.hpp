#pragma once
#include <cstddef>
#include <iostream>
#include <iterator>

namespace ess {
/* To build a iterator class
 * 1. operator override, !=, ==,
 */
class VecIterator {
public:
  explicit VecIterator(int *ptr) : ptr(ptr){};
  bool operator==(const VecIterator &other) const {
    return this->ptr == other.ptr;
  }
  bool operator!=(const VecIterator &other) const { return !(*this == other); }
  int &operator*() { return *this->ptr; }
  const int &operator*() const { return *this->ptr; }
  VecIterator &operator++() {
    this->ptr++;
    return *this;
  }
  VecIterator operator++(int) {
    auto tmp = this->ptr;
    ++this->ptr;
    return VecIterator(tmp);
  }

private:
  // turned out STL does no boundary checking
  void checkup();

private:
  /* const Vec& _vec; */
  /* std::size_t _index; */
  int *ptr;
};
}; // namespace ess
