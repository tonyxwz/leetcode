#include <algorithm>
#include <iostream>
#include <utility>

class MovableArray
{
public:
  MovableArray()
    : size_{ 0 }
    , data_{ nullptr }
  {}
  explicit MovableArray(int size) // ctor
    : size_(size)
    , data_{ new int[size]() } {};
  ~MovableArray() // dtor
  {
    delete[] data_;
    std::cout << "deleted array of size " << size_ << std::endl;
  };
  MovableArray(const MovableArray& other) // copy constructor
    : size_{ other.size_ }
    , data_{ new int[size_]() }
  {
    std::copy(other.data_, other.data_ + other.size_, this->data_);
    std::cout << "Array of size " << size_ << " is copied\n";
  }

  MovableArray(MovableArray&& other) // move constructor
    : MovableArray()
  {
    swap(*this, other);
    std::cout << "Array of size " << size_ << " is moved\n";
  }

  friend void swap(MovableArray& a, MovableArray& b) throw()
  {
    using std::swap;
    swap(a.data_, b.data_);
    swap(a.size_, b.size_);
  }
  int size() const { return this->size_; }
  int operator[](int i) const { return data_[i]; }
  int& operator[](int i) { return data_[i]; }

private:
  MovableArray& operator=(const MovableArray& rhs); // copy operator
  MovableArray& operator=(MovableArray&& rhs);      // move operator
  // MovableArray& operator=(MovableArray rhs);        // both
  int size_;
  int* data_;
};
