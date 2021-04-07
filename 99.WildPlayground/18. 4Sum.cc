#include "leetcode.h"

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target)
  {
    const int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < n; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        const int t = target - nums[i] - nums[j];
        int l = j + 1, r = n - 1;
        while (l < r) {
          int twoSum = nums[l] + nums[r];
          if (twoSum == t) {
            ans.push_back({ nums[i], nums[j], nums[l], nums[r] });
            l++;
            while (l < r && nums[l] == nums[l - 1])
              l++;
            r--;
          } else if (twoSum < t)
            l++;
          else
            r--;
        }
      }
    }
    return ans;
  }
};