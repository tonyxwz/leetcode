#include "leetcode.h"

// Note: dp[i][j] := maximum of edge of squares whose bottom right corner is at
// i,j
class Solution
{
public:
  int maximalSquare(vector<vector<char>>& M)
  {
    const int m = M.size();
    if (m == 0)
      return 0;
    const int n = M[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (M[i][j] == '1') {
          if (i > 0 && j > 0) {
            int r = min(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
            int c = min(dp[i - 1][j - 1], dp[i][j - 1]) + 1;
            int e = min(r, c);
            dp[i][j] = e;
          } else {
            dp[i][j] = 1;
          }
          ans = max(ans, dp[i][j] * dp[i][j]);
        }
      }
    }

    return ans;
  }
};

/*
[["1","1","1","1","0"],
 ["1","1","1","1","0"],
 ["1","1","1","1","1"],
 ["1","1","1","1","1"],
 ["0","0","1","1","1"]]
*/