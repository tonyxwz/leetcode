#pragma once
#include "VecIterator.hpp"
#include <algorithm>
#include <cstddef>

/* https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
 *
 * This is good for a class not used in polymorphism, but not enough for more
 * complicated cases. For class that requires polymorphism, you might also need
 * a virtual clone function.
 *
 */

namespace ess {

class Vec {
public:
  // rule of five
  // constructor
  Vec();
  // constructor v2
  explicit Vec(std::size_t size);
  explicit Vec(std::size_t size, const int init);
  // destructor -> 1
  ~Vec();
  // copy constructor -> 2
  Vec(const Vec &other);
  // copy assignment operator -> 3
  friend void swap(Vec &first, Vec &second);
  Vec &operator=(Vec other); // let c++ make copy in the argument list
  // alternative implementation not using copy and swap
  /* Vec &operator=(const Vec &other); */
  // move constructor -> 4
  Vec(const Vec &&other);
  // move assignment operator -> 5
  Vec &&operator=(Vec &&other);

  int &operator[](std::size_t i);
  const int &operator[](std::size_t i) const;

  // find swap using ADL (Argument dependent lookup)
  // but the use have to use unqualified call, swap(a, b), not std::swap(a, b)
  inline int size() const { return _max_size; }
  void push_back();

public:
  typedef VecIterator iterator;
  iterator begin();
  iterator end();

private:
  void check_range(std::size_t);
  void allocate_more();
  std::size_t _max_size;
  int *_data;
};

}; // namespace ess
