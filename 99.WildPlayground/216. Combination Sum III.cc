#include "leetcode.h"

class Solution
{
public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<int> curr;
    vector<vector<int>> ans;
    combination(curr, 0, k, n, ans);
    return ans;
  }
  void combination(vector<int>& curr,
                   int sums,
                   const int k,
                   const int n,
                   vector<vector<int>>& ans)
  {
    if (curr.size() == k) {
      if (sums == n)
        ans.push_back(curr);
      return;
    }
    for (int i = curr.empty() ? 1 : curr.back() + 1; i <= 9; ++i) {
      if (sums + i > n)
        break;
      curr.push_back(i);
      combination(curr, sums + i, k, n, ans);
      curr.pop_back();
    }
  }
};