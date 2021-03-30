#include "leetcode.h"

class Solution
{
public:
  int longestConsecutive(vector<int>& nums)
  {
    // end with key, start with key
    sort(nums.begin(), nums.end());
    unordered_map<int, int> dp;
    int ans = 0;
    for (const int i : nums) {
      int l = dp[i - 1] + 1;
      ans = max(ans, l);
      dp[i] = l;
    }
    return ans;
  }
};
