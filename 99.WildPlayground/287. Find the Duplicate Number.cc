#include "leetcode.h"

// Binary Search

class Solution
{
public:
  int findDuplicate(vector<int>& nums)
  {
    const int n = nums.size() - 1;
    sort(nums.begin(), nums.end());

    int l = 0, r = n;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] <= m) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};