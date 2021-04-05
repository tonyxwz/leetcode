#include "leetcode.h"

class Solution
{
public:
  vector<int> grayCode(int n)
  {
    vector<int> ans;
    dfs(n, ans);
    return ans;
  }
  void dfs(int n, vector<int>& ans)
  {
    if (n == 0) {
      ans.push_back(0);
      return;
    }
    dfs(n - 1, ans);
    for (int i = ans.size() - 1; i >= 0; --i)
      ans.push_back((1 << (n - 1)) | ans[i]);
  }
};