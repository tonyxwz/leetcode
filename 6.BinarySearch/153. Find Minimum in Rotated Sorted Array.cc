#include "leetcode.h"
/* 
这个方法没有考虑相同元素的可能
 */

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      if (nums[l] < nums[r]) return nums[l];
      int m = l + (r - l) / 2;
      if (nums[m] < nums[l]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return nums[l];
  }

  int findMin2(vector<int>& nums) {
    return recursive(nums, 0, nums.size() - 1);
  }

  int recursive(vector<int>& nums, int l, int r) {
    if (nums[l] <= nums[r]) return nums[l];
    int m = l + (r - l) / 2;
    if (nums[m] < nums[l]) return recursive(nums, l, m);
    return recursive(nums, m + 1, r);
  }
};