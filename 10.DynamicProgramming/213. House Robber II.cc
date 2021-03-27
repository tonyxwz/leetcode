#include "leetcode.h"

// Note: run House Robber twice one subarrays of the circle
// The final answer must be one of them.
//
// even if the solution on nums[1:] doesn't use nums[-1], the expected answer
// would be the solution on nums[:n-1]

class Solution
{
public:
  int rob(vector<int>& nums)
  {
    const int n = nums.size();
    if (n == 1)
      return nums[0];

    int curr = 0, pre = 0, tmp, ans;

    for (int i = 0; i < n - 1; ++i)
      tmp = curr, curr = max(curr, pre + nums[i]), pre = tmp;

    ans = curr;
    curr = pre = 0;

    for (int i = 1; i < n; ++i)
      tmp = curr, curr = max(curr, pre + nums[i]), pre = tmp;

    return max(ans, curr);
  }
};
