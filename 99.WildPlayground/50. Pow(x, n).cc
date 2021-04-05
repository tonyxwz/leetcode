#include "leetcode.h"

class Solution
{
public:
  double myPow(double x, int n)
  {
    int n_ = abs(n);
    if (n_ == 0)
      return 1.0;

    double half = myPow(x, n_ / 2);
    double ans = half * half;
    if (n_ & 1)
      ans = ans * x;
    if (n < 0)
      ans = 1 / ans;
    return ans;
  }
};