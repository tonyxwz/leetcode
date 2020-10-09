// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
#include "leetcode.h"

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    const int n = matrix.size();
    int l = matrix[0][0];
    int r = matrix[n - 1][n - 1] + 1;

    while (l < r) {
      int m = l + (r - l) / 2;
      int t = 0;
      for (auto row : matrix) {
        t += distance(row.begin(), upper_bound(row.begin(), row.end(), m));
      }
      // the following logic is correct only because the question promised that
      // k is always valid. In real problems, this might not be the case and the
      // number found by this method is the element `x` where there are `n` 
      // elements in the array smaller than x and `n` is smaller than `k`.
      if (t < k) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return l;
  }
};
