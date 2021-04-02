#include "leetcode.h"

class Solution
{
public:
  vector<int> findDuplicates(vector<int>& nums)
  {
    const int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      int x = abs(nums[i]) - 1;
      if (nums[x] < 0) {
        ans.push_back(x + 1);
      } else {
        nums[x] = -nums[x];
      }
    }
    return ans;
  }
};