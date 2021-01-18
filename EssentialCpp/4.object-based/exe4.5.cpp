#include <algorithm>
#include <iostream>
#include <vector>

namespace ess {

typedef float elemType;
/* template<typename elemType> */
class Mat {
  // for transition into a template

public:
  Mat(elemType a00 = 0., elemType a01 = 0., elemType a03 = 0.,
      elemType a04 = 0., elemType a10 = 0., elemType a11 = 0.,
      elemType a12 = 0., elemType a13 = 0., elemType a20 = 0.,
      elemType a21 = 0., elemType a22 = 0., elemType a23 = 0.,
      elemType a30 = 0., elemType a31 = 0., elemType a32 = 0.,
      elemType a33 = 0.);
  explicit Mat(const elemType *elems);
  // ~Mat();

public:
  int rows() const { return 4; }
  int cols() const { return 4; }

  std::ostream &print(std::ostream &os = std::cout) const;
  Mat operator+(const Mat &other) const;
  Mat operator+(const elemType a) const;
  Mat operator*(const Mat &other) const; // order matters
  Mat operator*(const elemType a) const; // order matters
  void operator+=(const Mat &other);
  void operator+=(const elemType a);
  elemType &operator()(int y, int x) { return _data[y][x]; }
  elemType operator()(int y, int x) const { return _data[y][x]; }

private:
  elemType _data[4][4];
  std::vector<int> seq;
};

Mat operator+(const elemType a, const Mat &other) { return other + a; }
Mat operator*(const elemType a, const Mat &other) { return other * a; }

Mat::Mat(elemType a00, elemType a01, elemType a02, elemType a03, elemType a10,
         elemType a11, elemType a12, elemType a13, elemType a20, elemType a21,
         elemType a22, elemType a23, elemType a30, elemType a31, elemType a32,
         elemType a33) {
  _data[0][0] = a00;
  _data[0][1] = a01;
  _data[0][2] = a02;
  _data[0][3] = a03;
  _data[1][0] = a10;
  _data[1][1] = a11;
  _data[1][2] = a12;
  _data[1][3] = a13;
  _data[2][0] = a20;
  _data[2][1] = a21;
  _data[2][2] = a22;
  _data[2][3] = a23;
  _data[3][0] = a30;
  _data[3][1] = a31;
  _data[3][2] = a32;
  _data[3][3] = a33;
}

Mat::Mat(const elemType *elems) {
  for (int j = 0; j < 4; ++j)
    for (int i = 0; i < 4; ++i)
      _data[j][i] = elems[j * 4 + i];
}

std::ostream &Mat::print(std::ostream &os) const {
  for (int i = 0; i < rows(); ++i) {
    os << (i == 0 ? "[[ " : " [ ");
    for (int j = 0; j < cols(); ++j) {
      os << _data[i][j] << (j == cols() - 1 ? " " : ", ");
    }
    os << (i == rows()-1 ? "]]\n" : "],\n");
  }
  return os;
}

Mat Mat::operator+(const Mat &other) const {
  Mat result(*this);
  for (int i = 0; i < rows(); ++i)
    for (int j = 0; j < cols(); ++j)
      result._data[i][j] = result._data[i][j] * other._data[i][j];
  return result;
};
Mat Mat::operator+(const elemType a) const {
  Mat result(*this);
  for (int i = 0; i < rows(); ++i)
    for (int j = 0; j < cols(); ++j)
      result._data[i][j] = result._data[i][j] + a;
  return result;
}
Mat Mat::operator*(const Mat &other) const {
  Mat result;
  for (int i = 0; i < rows(); ++i)
    for (int j = 0; j < cols(); ++j)
      for (int k = 0; k < cols(); ++k)
        result(i, j) += (*this)(i, k) * other(k, j);
  return result;
}
Mat Mat::operator*(const elemType a) const {
  Mat result(*this);
  for (int i = 0; i < rows(); ++i)
    for (int j = 0; j < cols(); ++j)
      result._data[i][j] = result._data[i][j] * a;
  return result;
}
void Mat::operator+=(const Mat &other) {
  for (int i = 0; i < rows(); ++i)
    for (int j = 0; j < cols(); ++j)
      _data[i][j] += other(i,j);
}
void Mat::operator+=(const elemType a) {
  for (int i = 0; i < rows(); ++i)
    for (int j = 0; j < cols(); ++j)
      _data[i][j] += a;
}
}; // namespace ess

int main() {
  using namespace ess;
  Mat a(1.9, 2.3, 3.5, 4.1, 1.2, 2.2, 3.9, 4.1, 1.4, 2.7, 3.9, 4.2, 1.6, 2.6, 3.8, 4.1);
  Mat b(4, 3, 2, 1, 4, 3, 2, 1, 4, 3, 2, 1, 4, 3, 2, 1);
  Mat c = a * b;
  Mat d = b * a;
  c.print();
  d.print();
}
