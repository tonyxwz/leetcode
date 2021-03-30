#include "leetcode.h"

class Solution
{
public:
  int singleNumber(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());
    int i = 1;
    for (; i < nums.size(); i = i + 2)
      if (i >= nums.size() || nums[i] != nums[i - 1])
        break;
    return nums[i - 1];
  }
};
