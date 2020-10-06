#include "leetcode.h"
// https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    if (arr.size() > 2) {
      int l = 0, r = arr.size() - 1;
      while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] < arr[m + 1])
          l = m + 1;
        else
          r = m;
      }
      return l;
    } else {
      return -1;
    }
  }
};