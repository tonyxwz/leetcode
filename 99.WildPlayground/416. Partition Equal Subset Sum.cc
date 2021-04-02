#include "leetcode.h"

// Using Bitset
class Solution
{
public:
  bool canPartition(vector<int>& nums)
  {
    const int max_l = 200;
    const int max_n = 100;

    // 0 is always possible
    bitset<max_l * max_n / 2 + 1> bits(1);
    int sum = 0;
    for (const int n : nums) {
      bits |= (bits << n);
      sum += n;
    }

    return bits[sum >> 1] && !(1 & sum);
  }
};

// Note: 0/1 knapsack dynamic programming

// Without optimization
class Solution
{
public:
  bool canPartition(vector<int>& nums)
  {
    const int n = nums.size();
    const int tot = accumulate(nums.begin(), nums.end(), 0);
    if (tot & 1)
      return false;
    const int target = tot / 2;

    // dp[i][j] := sum of numbers in nums[: i] can be j
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, false));
    fill(dp[0].begin(), dp[0].end(), false);
    for (int i = 0; i <= n; ++i)
      dp[i][0] = true;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= target; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (j - nums[i - 1] >= 0)
          dp[i][j] |= dp[i - 1][j - nums[i - 1]];
      }
    }
    return dp[n][target];
  }
};

// With Optimization: 1D dp
class Solution2
{
public:
  bool canPartition(vector<int>& nums)
  {
    const int n = nums.size();
    const int tot = accumulate(nums.begin(), nums.end(), 0);
    if (tot & 1)
      return false;
    const int target = tot / 2;

    // dp[i][j] := sum of numbers in nums[: i] can be j
    // vector<vector<int>> dp(n+1, vector<int>(target + 1, false));
    vector<int> dp(target + 1, false);
    dp[0] = true;
    // fill(dp[0].begin(), dp[0].end(), false);
    // for(int i = 0; i <= n; ++i)
    //    dp[i][0] = true;

    for (int i = 1; i <= n; ++i) {
      vector<int> curr(target + 1, false);
      for (int j = 1; j <= target; ++j) {
        curr[j] = dp[j];
        if (j - nums[i - 1] >= 0)
          curr[j] |= dp[j - nums[i - 1]];
      }
      dp.swap(curr);
    }
    return dp[target];
  }
};