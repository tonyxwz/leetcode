#include <iostream>
#include <iterator>
#include <vector>
#include <exception>

/* Define you own iterator
 *
 * 1. define a container class of something
 * 2. define a corresponding iterator class of the container class
 * 3. use the iterator class as a nested class of the container class
 *
 *
 * Iterator class
 * operator overiding:
 * operator*: dereference iterator
 * operator==: equal
 * operator!=: not equal
 *
 */

class TriangularIterator
{
public:
  explicit TriangularIterator(int index)
    : _index(index - 1)
  {}
  bool operator==(const TriangularIterator& other) const;
  bool operator!=(const TriangularIterator& other) const;
  int operator*() const;
  TriangularIterator& operator++();   // prefix
  TriangularIterator operator++(int); // postfix

private:
  void check_integrity() const;
  int _index;
};

class Triangular
{
  friend class TriangularIterator;
  friend int iCanReadTriangular(int, int);

public:
  Triangular();

private:
  static std::vector<int> _elems;
};

/* Implementation of TriangularIterator */
// OOP encapsulation is at class level, not object level. so I have access to
// _index of other
inline bool
TriangularIterator::operator==(const TriangularIterator& other) const
{
  return this->_index == other._index;
}
inline bool
TriangularIterator::operator!=(const TriangularIterator& other) const
{
  return !(*this == other);
}
int
TriangularIterator::operator*() const
{
  check_integrity();
  return Triangular::_elems[_index];
}
inline void TriangularIterator::check_integrity() const {
  if (_index > Triangular::_max_elems)
    throw std::iterator_overflow();
  if 
}
