#include "leetcode.h"

class Solution
{
public:
  vector<vector<string>> solveNQueens(int n)
  {
    vector<pair<int, int>> curr;
    vector<vector<string>> ans;
    dfs(curr, n, ans);
    return ans;
  }
  void dfs(vector<pair<int, int>>& curr, int n, vector<vector<string>>& ans)
  {
    int r = curr.size();
    if (r == n) {
      vector<string> board(n, string(n, '.'));
      for (const auto& p : curr)
        board[p.first][p.second] = 'Q';

      ans.push_back(board);
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