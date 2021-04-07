#include "leetcode.h"

class Solution
{
public:
  int minSubArrayLen(int target, vector<int>& nums)
  {
    int l = 0, r = 0, n = nums.size();
    int s = 0, ans = INT_MAX;
    while (r < n) {
      while (r < n && s < target) {
        s += nums[r];
        r++;
      }
      while (l < r && s >= target) {
        ans = min(ans, r - l);
        s -= nums[l];
        l++;
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};