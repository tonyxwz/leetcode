#include "leetcode.h"

// Note: dp[i]: number of perfect squares numbers to sum up to i
class Solution
{
public:
  int numSquares(int n)
  {
    vector<int> dp(n + 1, INT_MAX / 2);

    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j * j <= i; ++j)
        dp[i] = min(dp[i], dp[i - j * j] + 1);
    return dp[n];
  }
};