#include <initializer_list>
#include <iostream>
#include <string>

template<int _rows, int _cols, typename T = float>
class Matrix
{
public:
  Matrix() // default
  {
    for (int i = 0; i < _rows; ++i) {
      _data[i] = new T[_cols]();
    }
  }
  explicit Matrix(const T* const data)
    : Matrix()
  {
    std::cout << "Construct from const c array" << std::endl;
    for (int i = 0, k = 0; i < _rows; ++i)
      for (int j = 0; j < _cols; ++j)
        _data[i][j] = data[k++];
  }
  explicit Matrix(const std::initializer_list<T>& l)
    : Matrix()
  {
    std::cout << "Construct from initializer_list" << std::endl;
    // assert l.size() == _rows * _cols
    auto it = l.begin();
    for (int i = 0; i < _rows; ++i)
      for (int j = 0; j < _cols; ++j)
        _data[i][j] = *it++;
  }
  Matrix& operator=(const Matrix& rhs); // copy assignment operator without swap
  // assignment from initializer_list
  Matrix& operator=(const std::initializer_list<T>& l)
  {
    std::cout << "Using operator=" << std::endl;
    auto it = l.cbegin();
    for (int i = 0; i < _rows; ++i)
      for (int j = 0; j < _cols; ++j)
        _data[i][j] = *it++;
    return *this;
  }
  ~Matrix()
  {
    for (int i = 0; i < _rows; ++i) {
      delete[] _data[i];
      std::cout << "freed data[" << i << "]" << std::endl;
    }
  }

public:
  int rows() { return _rows; }
  int cols() { return _cols; }
  std::ostream& print(std::ostream& os) const
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
  T& operator()(int row, int col) { return _data[row][col]; }
  const T& operator()(int row, int col) const { return _data[row][col]; }

  template<int newcols>
  Matrix<_rows, newcols, T> operator*(
    const Matrix<_cols, newcols, T>& other) const
  {
    Matrix<_rows, newcols, T> result;
    for (int i = 0; i < _rows; ++i) {
      for (int j = 0; j < newcols; ++j) {
        for (int k = 0; k < _cols; ++k) {
          result(i, j) += (*this)(i, k) * other(k, j);
        }
      }
    }
    return result;
  }
  Matrix operator+(const Matrix<_rows, _cols, T>& other) const
  {
    Matrix<_rows, _cols, T> result;
    for (int i = 0; i < _rows; ++i) {
      for (int j = 0; j < _cols; ++j) {
        result[i][j] = this->_data[i][j] + other(i, j);
      }
    }
    return result;
  }

private:
  T* _data[_rows];
};

template<int rows, int cols, typename T = float>
std::ostream&
operator<<(std::ostream& os, const Matrix<rows, cols, T>& mat)
{
  return mat.print(os);
}

int
main()
{
  using namespace std;
  Matrix<2, 4> a{ 1, 2, 3, 4, 5, 6, 7, 8 };
  Matrix<4, 3> b{ 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  cout << a << endl;
  cout << b << endl;
  cout << a * b << endl;
  return 0;
}
