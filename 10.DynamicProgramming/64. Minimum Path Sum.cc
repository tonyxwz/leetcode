#include "leetcode.h"

class Solution
{
public:
  int minPathSum(vector<vector<int>>& grid)
  {
    const int m = grid.size();
    if (m == 0)
      return 0;
    const int n = grid[0].size();

    // minimal path to go to i,j
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0)
          continue;
        if (i == 0) {
          dp[i][j] = dp[i][j - 1] + grid[i][j];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j] + grid[i][j];
        } else {
          dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};