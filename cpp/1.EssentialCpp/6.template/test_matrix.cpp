#include "Matrix2.hpp"
/* #include "leetcode.h" */
#include <gtest/gtest.h>

using ess::Matrix;
using std::cout;
/* using std::endl; */

int
main()
{
  auto I = Matrix<float>::eye(4);
  Matrix<float> A(2, 4);
  A = { 1, 2, 3, 4, 5, 6, 7, 8 };
  cout << A << I << A * I;
  return 0;
}
