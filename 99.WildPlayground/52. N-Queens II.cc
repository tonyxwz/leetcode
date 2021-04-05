#include "leetcode.h"

class Solution
{
public:
  int totalNQueens(int n)
  {
    vector<pair<int, int>> curr;
    int ans = 0;
    dfs(curr, n, ans);
    return ans;
  }
  void dfs(vector<pair<int, int>>& curr, int n, int& ans)
  {
    int r = curr.size();
    if (r == n) {
      ans++;
      return;
    }
    for (int c = 0; c < n; ++c) {
      bool ok = true;
      for (const auto& p : curr) {
        if (c == p.second || abs(r - p.first) == abs(c - p.second)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        curr.push_back({ r, c });
        dfs(curr, n, ans);
        curr.pop_back();
      }
    }
  }
};