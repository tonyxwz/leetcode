#include "leetcode.h"

class Solution
{
public:
  int jump(vector<int>& nums)
  {
    // shortest path
    int n = nums.size(), start = 0, end = 0, steps = 0;
    while (end < n - 1) {
      steps++;
      int maxend = end;
      for (int i = start; i <= end; ++i) {
        maxend = max(maxend, i + nums[i]);
      }
      start = end + 1;
      end = maxend;
    }
    return steps;
  }
};