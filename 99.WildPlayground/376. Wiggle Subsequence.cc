#include "leetcode.h"

class Solution
{
public:
  int wiggleMaxLength(vector<int>& nums)
  {
    const int n = nums.size();
    // if (n <= 1)
    //    return n;
    vector<pair<int, int>> dp(nums.size(), { 1, 1 });
    dp[0] = { 1, 1 };
    for (int i = 1; i < n; ++i) {
      if (nums[i] > nums[i - 1])
        dp[i].second = 2;
      else
        dp[i].first = 2;
      dp[i].first = 1; // nums[i] as going down
      dp[i].second = 1;
      for (int j = 0; j < i; ++j) {
        // cout << nums[i] << ", " << nums[j] << endl;
        if (nums[j] > nums[i])
          dp[i].first = max(dp[i].first, dp[j].second + 1);
        if (nums[j] < nums[i])
          dp[i].second = max(dp[i].second, dp[j].first + 1);
      }
    }
    int ans = 0;
    for (const auto& p : dp) {
      // cout << p.first << ", " << p.second << endl;
      ans = max(ans, max(p.first, p.second));
    }
    return ans;
  }
};

// an element could only be at 3 status, down, up, and equal
class Solution
{
public:
  int wiggleMaxLength(vector<int>& nums)
  {
    const int n = nums.size();
    if (n < 2)
      return n;
    int down = 1, up = 1;
    for (int i = 1; i < n; ++i) {
      if (nums[i] > nums[i - 1])
        up = down + 1;
      else if (nums[i] < nums[i - 1])
        down = up + 1;
    }
    return max(up, down);
  }
};