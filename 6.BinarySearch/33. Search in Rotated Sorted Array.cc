// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[l] < nums[m]) {
        if (target < nums[m] && target > nums[l]) {
          r = m;
        } else if (target > nums[m] || target < nums[l]) {
          l = m;
        } else if (target == nums[m])
          return m;
        else
          return l;
      } else {
        if (target > nums[m] && target < nums[l]) {
          l = m;
        } else if (target > nums[l] || target < nums[m]) {
          r = m;
        } else if (target == nums[m])
          return m;
        else
          return l;
      }
    }
    return -1;
  }
};