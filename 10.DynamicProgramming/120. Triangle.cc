#include "leetcode.h"

class Solution
{
public:
  int minimumTotal(vector<vector<int>>& triangle)
  {
    const int L = triangle.size();
    vector<vector<int>> dp;
    dp.push_back(triangle[0]);

    for (int i = 0; i < L - 1; ++i) {
      dp.push_back(vector<int>(triangle[i + 1].size(), INT_MAX));

      for (int j = 0, n = triangle[i].size(); j < n; ++j) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
        dp[i + 1][j + 1] =
          min(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
      }
    }

    return *min_element(dp.back().begin(), dp.back().end());
  }
};