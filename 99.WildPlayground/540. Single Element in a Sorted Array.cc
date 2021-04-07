#include "leetcode.h"

class Solution
{
public:
  int singleNonDuplicate(vector<int>& nums)
  {
    // length: odd number
    int l = 0, r = nums.size();
    while (l + 1 < r) {
      int m = l + (r - l) / 2;
      m = m & (~1);
      if (nums[m] == nums[m + 1])
        l = m + 2;
      else
        r = m;
    }
    return nums[l];
  }
};