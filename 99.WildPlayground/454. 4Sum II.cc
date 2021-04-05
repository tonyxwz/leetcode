#include "leetcode.h"
class Solution
{
public:
  int fourSumCount(vector<int>& A,
                   vector<int>& B,
                   vector<int>& C,
                   vector<int>& D)
  {
    unordered_map<int, int> ab, cd;
    const int N = A.size();
    int ans = 0;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        ab[A[i] + B[j]]++;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        ans += ab[-C[i] - D[j]];
      }
    }
    return ans;
  }
};