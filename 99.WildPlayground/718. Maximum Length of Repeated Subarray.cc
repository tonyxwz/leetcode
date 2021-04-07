#include "leetcode.h"

class Solution
{
public:
  int findLength(vector<int>& A, vector<int>& B)
  {
    const int m = A.size(), n = B.size();
    vector<int> pre(n + 1, 0), curr(n + 1, 0);

    int max_len = 0;
    for (int i = 1; i < m; ++i) {   // A
      for (int j = 1; j <= n; ++j) { // B
        if (A[i - 1] == B[j - 1]) {
          curr[j] = 1 + pre[j - 1];
          max_len = max(max_len, curr[j]);
        }
      }
      pre.swap(curr);
    }
    return max_len;
  }
};
