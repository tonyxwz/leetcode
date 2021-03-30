#include "leetcode.h"

class Solution
{
public:
  bool canJump(vector<int>& nums)
  {
    int start = 0, end = 0, n = nums.size();
    while (start <= end) {
      // cout << start << "," << end << endl;
      if (end >= n - 1 && start <= n - 1)
        return true;
      int maxend = start;
      for (int i = start; i <= end; ++i) {
        maxend = max(maxend, i + nums[i]);
      }
      start = end + 1;
      end = maxend;
    }
    return false;
  }
};