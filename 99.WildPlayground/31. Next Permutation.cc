#include "leetcode.h"

class Solution
{
public:
  void nextPermutation(vector<int>& nums)
  {
    int m = INT_MAX;
    const int n = nums.size();
    int l = 0;
    for (int i = n - 1; i > 0; --i) {
      if (nums[i] > nums[i - 1]) {
        l = i;
        break;
      }
    }
    // [l:] is in descending order
    reverse(nums.begin() + l, nums.end());

    if (l > 0) {
      int r = l;
      for (; r < n; ++r) {
        if (nums[r] > nums[l - 1]) {
          swap(nums[r], nums[l - 1]);
          break;
        }
      }
    }
  }
};
