#include "leetcode.h"

class Solution
{
public:
  int minimumMoves(vector<vector<int>>& grid)
  {
    const int n = grid.size();
    // first: --, second: |
    vector<vector<pair<int, int>>> dp(
      n + 1, vector<pair<int, int>>(n + 1, { INT_MAX / 2, INT_MAX / 2 }));

    dp[0][1].first = -1;
    dp[1][0].first = -1;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        bool h = false, v = false;
        if (!grid[i - 1][j - 1] && j < n && !grid[i - 1][j]) {
          dp[i][j].first = min(dp[i][j - 1].first, dp[i - 1][j].first) + 1;
          h = true; // can rotate from h to v
        }
        if (!grid[i - 1][j - 1] && i < n && !grid[i][j - 1]) {
          dp[i][j].second = min(dp[i - 1][j].second, dp[i][j - 1].second) + 1;
          v = true; // can rotate from v to h
        }
        if (h && i < n && !grid[i][j])
          dp[i][j].first = min(dp[i][j].first, dp[i][j].second + 1);

        if (v && j < n && !grid[i][j])
          dp[i][j].second = min(dp[i][j].second, dp[i][j].first + 1);
      }
    }

    return dp[n][n - 1].first >= INT_MAX / 2 ? -1 : dp[n][n - 1].first;
  }
};
