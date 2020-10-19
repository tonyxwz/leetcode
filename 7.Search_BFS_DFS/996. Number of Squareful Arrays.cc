#include "leetcode.h"

class Solution
{
  bool isSquareful(const int& a, const int& b)
  {
    int root = sqrt(a + b);
    return (root * root) == (a + b);
  }

  void dfs(const vector<int>& A,
           int& ans,
           vector<int>& curr,
           vector<bool>& used)
  {
    if (curr.size() == A.size()) {
      ans++;
      return;
    }
    for (int i = 0; i < A.size(); i++) {
      // next digits cannot use the previously used digits
      if (used[i])
        continue;
      // if A[i] == A[i-1], then {..., A[i-1], A[i], ...} is already considered
      // by {..., A[i], A[i-1], ...}
      if (i > 0 && A[i] == A[i - 1] && !used[i - 1])
        continue;
      // not satisfying squareful requirements
      if (!curr.empty() && !isSquareful(A[i], curr.back()))
        continue;
      used[i] = true;
      curr.push_back(A[i]);
      dfs(A, ans, curr, used);
      curr.pop_back();
      used[i] = false;
    }
  }

public:
  int numSquarefulPerms(vector<int>& A)
  {
    vector<bool> used(A.size(), false);
    int ans = 0;
    vector<int> curr;
    sort(A.begin(), A.end());
    dfs(A, ans, curr, used);
    return ans;
  }
};