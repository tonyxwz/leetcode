#include "leetcode.h"

class Solution
{
public:
  int calculateMinimumHP(vector<vector<int>>& A)
  {
    const int rows = A.size();
    const int cols = A[0].size();

    // min health to reach to bottom right corner
    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, INT_MAX));
    dp[rows][cols - 1] = 1;
    dp[rows - 1][cols] = 1;

    for (int r = rows - 1; r >= 0; --r) {
      for (int c = cols - 1; c >= 0; --c) {
        dp[r][c] = max(1, min(dp[r + 1][c], dp[r][c + 1]) - A[r][c]);
      }
    }
    return dp[0][0];
  }
};
