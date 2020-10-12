#include "leetcode.h"
/* https://xie.infoq.cn/article/03b47ae0927607897fbd05b8e */
// reminder: lower bound
class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    const int n = nums.size();
    int l = 0;
    int r = nums.back() - nums.front() + 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      // m: middle
      // 接下来需要一个条件来判断计算距离 <= m的pair数量

      /* Dynamic programming used here:
      nums[i] and nums[j] forms a pair (nums[i], nums[j]).
      since nums is sorted, the absolute distance between the two is
          nums[j] - nums[i]
      we iterate on the entire array, for each element, there's another
      while loop trying to find the first j whose distance is greater than m.
      */
      int total = 0;
      int j = 0;
      for (int i = 0; i < n; i++) {
        while (j < n && nums[j] - nums[i] <= m) {
          j++;
        }
        // excluding the first pair (nums[i], nums[i]) and the last pair
        // (nums[i], nums[j])
        total += j - i - 1;
      }

      // lower bound guarantees that the kth distance is m
      /* 在上边的循环中，total是距离小于等于m的pair的数量，
      即m是第total个距离
      */
      if (total >= k) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};