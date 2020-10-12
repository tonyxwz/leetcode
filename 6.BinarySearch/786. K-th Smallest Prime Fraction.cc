#include "leetcode.h"

class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    const int n = A.size();
    double l = 0.0;
    double r = 1.0;
    while (l < r) {
      double m = (l + r) / 2;
      int total = 0;
      int p = 0, q = 1;

      // ratio closest to m
      double max_ratio = 0.0;
      int j = 1;
      for (int i = 0; i < n-1; i++) {
        // never use == to compare double/float
        while (j < n && A[i] > A[j] * m) {
          j++;
        } 
        // no following elements satisfies A[i]/A[j]<m for current i,
        // then the following i wont satisty either.
        // break and don't do anything.
        if (n == j) break;
        // A[i] / A[j] <= m is true for all from j till n-1 (exclude n)
        total += (n - j);
        double ratio = static_cast<double>(A[i]) / A[j];
        if (ratio > max_ratio) {
          max_ratio = ratio;
          p = i;
          q = j;
        }
      }
      if (total == K)
        return {A[p], A[q]};
      else if (total > K)
        r = m;
      else
        l = m;
    }
    return {};
  }
};