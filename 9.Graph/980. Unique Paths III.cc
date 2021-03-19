#include "leetcode.h"

class Solution
{
public:
  int uniquePathsIII(vector<vector<int>>& grid)
  {
    const int R = grid.size();
    const int C = grid[0].size();
    int sr, sc, er, ec;
    int stop_mask = (1 << (R * C)) - 1;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (grid[i][j] == 1) {
          sr = i;
          sc = j;
        } else if (grid[i][j] == 2) {
          er = i;
          ec = j;
        } else if (grid[i][j] < 0) {
          stop_mask &= ~(1 << (i * C + j));
        }
      }
    }

    int ans = 0;

    function<void(int, int, int)> dfs = [&](int r, int c, int visited) {
      if (r < 0 || r >= R || c < 0 || c >= C)
        return;
      if (grid[r][c] < 0)
        return;
      if (visited & (1 << (r * C + c)))
        return;
      visited = visited | (1 << (r * C + c));
      if (er == r && ec == c) {
        if (visited == stop_mask) {
          ans++;
        }
        return;
      }
      const static int dirs[5] = { 0, 1, 0, -1, 0 };
      for (int i = 0; i < 4; ++i) // todo '-1'
        dfs(r + dirs[i], c + dirs[i + 1], visited);
    };

    dfs(sr, sc, 0);

    return ans;
  }
};