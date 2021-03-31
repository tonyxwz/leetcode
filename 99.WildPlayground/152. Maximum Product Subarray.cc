#include "leetcode.h"

class Solution
{
public:
  int maxProduct(vector<int>& nums)
  {
    const int n = nums.size();
    if (n == 1)
      return nums[0];
    vector<pair<int, int>> dp(n + 1, { 0, 0 });
    // first: max non-neg
    // second: min non-pos
    for (int i = 1; i <= n; ++i) {
      if (nums[i - 1] == 0) {
        dp[i].first = 0, dp[i].second = 0;
      } else if (nums[i - 1] > 0) {
        dp[i].first = max(nums[i - 1], dp[i - 1].first * nums[i - 1]);
        dp[i].second = nums[i - 1] * dp[i - 1].second;
      } else {
        dp[i].first = dp[i - 1].second * nums[i - 1];
        dp[i].second = min(nums[i - 1], dp[i - 1].first * nums[i - 1]);
      }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; ++i)
      ans = max(ans, dp[i].first);
    return ans;
  }
};