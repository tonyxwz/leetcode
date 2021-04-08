#include "leetcode.h"

class Solution
{
public:
  int integerBreak(int n)
  {
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
      int div = n / i;
      int defi = n - div * i;
      int prod = 1;
      for (int j = 0; j < i - defi; ++j)
        prod *= div;
      for (int j = 0; j < defi; ++j)
        prod *= (div + 1);
      ans = max(ans, prod);
    }
    return ans;
  }
};