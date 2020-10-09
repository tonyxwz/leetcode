#include "leetcode.h"

// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
/* Reminders:
从这道题中可以总结出很多二分法搜索的规律
当使用`l < r`作为边界条件的时候，最终停止的条件一定是`l == r`
而从if的另一个分支中可以看出，r是满足t>=k的最小的数。

所以这个解法不会返回一个质数（在乘法表中不存在），因为总有一个比这个质数小的合数在二分搜索的路径中。
 */
class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    if (m > n) return findKthNumber(n, m, k);
    int l = 1;
    int r = m * n + 1;

    while (l < r) {
      const int mid = l + (r - l) / 2;
      int t = 0;
      for (int i = 1; i <= m; i++) {
        t += min(n, mid / i);
      }
      if (t >= k)
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
};