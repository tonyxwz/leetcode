#include "leetcode.h"

class Solution
{
public:
  int maximalRectangle(vector<vector<char>>& M)
  {
    const int n = M.size();
    if (n == 0)
      return 0;
    const int m = M[0].size();

    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (M[i][j] == '1')
          dp[i][j] = (j == 0 ? 1 : dp[i][j - 1] + 1);

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int len = INT_MAX;
        for (int k = i; k >= 0; --k) {
          len = min(len, dp[k][j]);
          if (len == 0)
            break;
          ans = max(ans, len * (i - k + 1));
        }
      }
    }
    return ans;
  }
};