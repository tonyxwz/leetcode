// https://leetcode.com/problems/find-peak-element/
// MIT 6.006 Intro to Algorithms
// https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec01.pdf

#include "leetcode.h"
// the solution looks wired because nums[-1] and nums[n] are infinity. 
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    // return recursive(nums, 0, nums.size()-1);
    return iterative(nums);
  }
  int recursive(vector<int>& nums, int l, int r) {
    if (l == r) return l;
    int m = l + (r - l) / 2;
    if (nums[m] > nums[m + 1]) return recursive(nums, l, m);
    return recursive(nums, m + 1, r);
  }

  int iterative(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > nums[m + 1])
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
