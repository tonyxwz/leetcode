#include "leetcode.h"

class Solution
{
public:
  int numTrees(int n)
  {
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) // number of digits to use
      for (int j = 0; j < i; ++j)
        dp[i] += dp[j] * dp[i - 1 - j];
    return dp.back();
  }
};