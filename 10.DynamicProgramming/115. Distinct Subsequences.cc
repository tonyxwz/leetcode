#include "leetcode.h"

class Solution
{
public:
  int numDistinct(string s, string t)
  {
    const int m = s.length(), n = t.length();
    vector<vector<long>> dp(n + 1, vector<long>(m + 1, 0));
    fill(begin(dp[0]), end(dp[0]), 1);

    for (int i = 1; i <= n; ++i)   // t
      for (int j = 1; j <= m; ++j) // s
        dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
    return dp[n][m];
  }
};