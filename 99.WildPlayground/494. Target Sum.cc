#include "leetcode.h"

// Note Dynamic Programming

class Solution
{
public:
  int findTargetSumWays(vector<int>& nums, int S)
  {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(2001, 0));
    dp[0][0 + 1000] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int x = -1000; x <= 1000; ++x) {
        int x_ = x + 1000;
        if (x_ - nums[i - 1] >= 0)
          dp[i][x_] += dp[i - 1][x_ - nums[i - 1]];
        if (x_ + nums[i - 1] <= 2000)
          dp[i][x_] += dp[i - 1][x_ + nums[i - 1]];
      }
    }
    return S >= -1000 && S <= 1000 ? dp[n][S + 1000] : 0;
  }

  int findTargetSumWays2(vector<int>& nums, int S)
  {
    int n = 0;
    dfs(0, 0, nums, S, n);
    return n;
  }

  void dfs(int i, int sum, const vector<int>& nums, const int S, int& n)
  {
    if (i == nums.size()) {
      if (sum == S)
        n++;
      return;
    }
    dfs(i + 1, sum + nums[i], nums, S, n);
    dfs(i + 1, sum - nums[i], nums, S, n);
  }
};