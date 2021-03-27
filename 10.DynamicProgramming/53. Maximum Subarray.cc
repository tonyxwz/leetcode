#include "leetcode.h"

class Solution
{
public:
  int maxSubArray(vector<int>& nums)
  {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    for (int i = 1, n = nums.size(); i < n; ++i) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }
    return *max_element(dp.begin(), dp.end());
  }
};