#pragma once
#include <algorithm>
#include <initializer_list>
#include <iostream>
namespace ess {

template<typename T>
class DummyVector
{
public:
  DummyVector()
    : DummyVector(0)
  {}
  // new knowledge, the order of initialization in the initialization list
  // should be the same as the order in member definition.
  explicit DummyVector(size_t size)
    : _data(size ? new T[size]() : nullptr)
    , _size(size)
    , _capacity(0)
  {}
  explicit DummyVector(std::initializer_list<T> lst)
    : DummyVector(lst.size())
  {
    _capacity = _size;
    std::copy(lst.begin(), lst.end(), _data);
  }
  ~DummyVector() { delete[] _data; }

public:
  class iterator;
  iterator begin() { return iterator(_data); }
  iterator end() { return iterator(_data + _size); }
  class const_iterator;
  const_iterator cbegin() const;
  const_iterator cend() const;

public:
  void push_back(T x);

private:
  T* _data;
  size_t _size;
  size_t _capacity;
};

/* iterators {{{ */

template<typename T>
class DummyVector<T>::iterator
{
public:
  explicit iterator(T* ptr)
    : _ptr(ptr)
  {}
  T& operator*() { return *this->_ptr; }
  iterator& operator++()
  {
    ++_ptr;
    return *this;
  }
  // postfix
  iterator operator++(int)
  {
    iterator tmp = *this;
    ++_ptr;
    return tmp;
  }
  bool operator==(const iterator& rhs) const { return this->_ptr == rhs._ptr; }
  bool operator!=(const iterator& rhs) const { return !(*this == rhs); }

private:
  T* _ptr;
};
/* https://stackoverflow.com/questions/2150192/how-to-avoid-code-duplication-implementing-const-and-non-const-iterators
 */
template<typename T>
class DummyVector<T>::const_iterator : DummyVector<T>::iterator
{};
/* }}} */

}; // namespace ess
