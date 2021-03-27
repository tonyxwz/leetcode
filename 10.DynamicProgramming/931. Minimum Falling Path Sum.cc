#include "leetcode.h"

class Solution
{
public:
  int minFallingPathSum(vector<vector<int>>& matrix)
  {
    const int n = matrix.size();

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    std::copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());

    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + matrix[i + 1][j]);
        if (j > 0)
          dp[i + 1][j - 1] =
            min(dp[i + 1][j - 1], dp[i][j] + matrix[i + 1][j - 1]);
        if (j < n - 1)
          dp[i + 1][j + 1] =
            min(dp[i + 1][j + 1], dp[i][j] + matrix[i + 1][j + 1]);
      }
    }

    return *min_element(dp.back().begin(), dp.back().end());
  }
};