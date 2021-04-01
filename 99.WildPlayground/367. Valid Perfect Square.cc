#include "leetcode.h"
// Binary Search
class Solution
{
public:
  bool isPerfectSquare(int num)
  {
    int l = 1, r = num;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int q = num / mid;
      int m = num % mid;
      if (q == mid && m == 0)
        return true;
      else if (q > mid) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return false;
  }
};