#include <iostream>
#include <new>
#include <utility>

namespace ess {

template<typename elemType>
class Matrix
{

public:
  // prototypes {{{
  Matrix() = delete;
  explicit Matrix(unsigned int size) // square matrix
    : Matrix(size, size)
  {}

  Matrix(unsigned int rows, unsigned int cols) // all zeros
    : _rows{ rows }
    , _cols{ cols }
  {
    // IMPORTANT 2D new initialization
    _data = new elemType*[_rows]();
    for (unsigned int i = 0; i < _rows; ++i)
      _data[i] = new elemType[_cols]();
  }

  Matrix(unsigned int rows, unsigned int cols, const elemType& val)
    : Matrix(rows, cols)
  {
    for (int i = 0; i < _rows; ++i)
      for (int j = 0; j < _cols; ++j)
        _data[i][j] = val;
  }

  Matrix(
    unsigned int rows,
    unsigned int cols,
    const elemType*& array) // with data, guarantte that array is not nullptr
    : Matrix(rows, cols)
  {
    for (unsigned int i = 0, k = 0; i < _rows; ++i)
      for (unsigned int j = 0; j < _cols; ++j)
        _data[i][j] = array[k++];
  }

  // big 4.5, with copy and swap
  friend void swap(Matrix& a, Matrix& b) noexcept
  {
    using std::swap;
    swap(a._data, b._data);
    swap(a._cols, b._cols);
    swap(a._rows, b._rows);
  }

  // copy construct
  Matrix(const Matrix& other)
    : Matrix(other._rows, other._cols)
  {
    for (int i = 0; i < _rows; ++i)
      std::copy(other._data[i], other._data[i] + other._cols, this->_data[i]);
  }

  // copy assignment + move assignment (because rhs is taken by value)
  Matrix& operator=(Matrix rhs)
  {
    swap(*this, rhs);
    return *this;
  }
  /* Matrix& operator=(Matrix&& rhs);      // move assignment */

  // move construct
  Matrix(Matrix&& other)
    : Matrix(other._rows, other._cols)
  {
    std::cout << "moved" << std::endl;
    swap(*this, other);
  }

  ~Matrix()
  {
    for (int i = 0; i < _rows; ++i)
      delete[] _data[i];
    delete[] _data;
  }

  // }}}

  // methods {{{
  unsigned int rows() const { return _rows; }
  unsigned int cols() const { return _cols; }
  std::pair<unsigned int, unsigned int> size() const
  {
    return { _rows, _cols };
  }

  std::ostream& print(std::ostream& os = std::cout) const
  {
    for (int i = 0; i < _rows; ++i) {
      os << (i == 0 ? "[[ " : " [ ");
      for (int j = 0; j < _cols; ++j) {
        os << _data[i][j] << (j == _cols - 1 ? " " : ",\t");
      }
      os << (i == _rows - 1 ? "]]" : "],") << std::endl;
    }
    return os;
  }
  // transpose
  Matrix T() const
  {
    Matrix mat(this->_cols, this->_rows);
    for (int i = 0; i < this->_rows; ++i)
      for (int j = 0; j < this->_cols; ++j)
        mat(j, i) = this->_data[i][j];
    return mat;
  }
  // }}}

  // operators {{{
  elemType operator()(unsigned int i, unsigned int j) const
  {
    return _data[i][j];
  }
  elemType& operator()(unsigned int i, unsigned int j) { return _data[i][j]; }
  bool operator==(const Matrix& other) const { return true; } // TODO
  bool operator!=(const Matrix& other) const { return !(*this == other); }
  Matrix operator*(const Matrix& other) const
  {
    // assert this->_cols == other._rows
    Matrix mat(this->_rows, other._cols);
    for (int i = 0; i < this->_rows; ++i)
      for (int j = 0; j < other._cols; ++j)
        for (int k = 0; k < this->_cols; ++k)
          mat(i, j) += (*this)(i, k) * other(k, j);
    return mat;
  };
  Matrix operator+(const Matrix& other) const
  {
    // assert equal size
    Matrix mat(this->size());
    for (int i = 0; i < this->_rows; ++i)
      for (int j = 0; j < this->_cols; ++j)
        mat(i, j) = (*this)(i, j) + other(i, j);
    return mat;
  }
  Matrix& operator=(const std::initializer_list<elemType>& l)
  {
    // assert l.size() == _rows * _cols;
    auto it = l.begin();
    for (int i = 0; i < _rows; ++i)
      for (int j = 0; j < _cols; ++j)
        _data[i][j] = *it++;
    return *this;
  }

  // }}}

  // static methods {{{
  static Matrix ones(unsigned int rows, unsigned int cols)
  {
    Matrix mat(rows, cols, 1.0);
    return mat;
  }
  static Matrix zeros(unsigned int rows, unsigned int cols)
  {
    Matrix mat(rows, cols, 0.0);
    return mat;
  }
  static Matrix eye(unsigned int length)
  {
    Matrix mat(length);
    for (int i = 0; i < mat.rows(); ++i)
      mat(i, i) = 1;
    return mat;
  }
  // }}}

private:
  // {{{
  unsigned int _rows;
  unsigned int _cols;
  elemType** _data;
  // }}}
};

template<typename elemType>
std::ostream&
operator<<(std::ostream& os, const Matrix<elemType>& mat)
{
  return mat.print(os);
}

} // namespace ess
