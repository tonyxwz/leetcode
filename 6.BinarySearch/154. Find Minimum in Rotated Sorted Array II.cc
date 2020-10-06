// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
#include "leetcode.h"

// TODO is it possible to implement this solution with `r` being the 
// off-edge iterator?

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      if (nums[l] < nums[r])
        return nums[l];

      int m = l + (r - l) / 2;
      if (nums[m] > nums[l])
        l = m + 1;
      else if (nums[m] < nums[l])
        r = m;
      else
        l++;
    }
    return nums[l];
  }
};