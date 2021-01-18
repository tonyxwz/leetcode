#include "leetcode.h"

// Author: Huahua, 48 ms, 13.4 MB
class Solution
{
public:
  int maxDistance(vector<vector<int>>& grid)
  {
    const int n = grid.size();
    const int m = grid[0].size();
    int ans = -1;
    queue<int> q; // y*100 + x
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j] == 1)
          q.push(i * 100 + j);
    vector<int> dirs{ 0, -1, 0, 1, 0 };
    int steps = 0;
    while (q.size()) {
      int size = q.size();
      // each round is a layer, so the basic principle is the same
      while (size--) {
        auto p = q.front();
        q.pop();
        int x = p % 100;
        int y = p / 100;
        if (grid[y][x] == 2)
          ans = max(ans, steps);
        for (int i = 0; i < 4; ++i) {
          int tx = x + dirs[i];
          int ty = y + dirs[i + 1];
          if (tx < 0 || tx >= m || ty < 0 || ty >= n || grid[ty][tx] != 0)
            continue;
          grid[ty][tx] = 2;
          q.push(ty * 100 + tx);
        }
      }
      ++steps;
    }
    return ans;
  }
};

class Solution2
{
public:
  int maxDistance(vector<vector<int>>& grid)
  {
    // bfs for water cells
    int d = 0;
    int ans = -1;
    rows = grid.size();
    cols = grid[0].size();

    bool changed = false;
    do {
      changed = dilate2d(grid, d);
      if (changed) {
        d++;
        ans = max(ans, d);
      }
    } while (changed);
    return ans;
  }

private:
  int rows;
  int cols;
  inline static const int dirs[] = { 0, -1, 0, 1, 0 };

  bool dilate2d(vector<vector<int>>& grid, const int d)
  {
    bool changed = false;
    const int target = d + 1; // value is 1 meaning distance is 0
    const int nextTarget = target + 1;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == target) {
          for (int k = 0; k < 4; ++k) {
            const int y = i + dirs[k];
            const int x = j + dirs[k + 1];
            if (y < 0 || y >= rows || x < 0 || x >= cols)
              continue;
            if (grid[y][x] != 0)
              continue;
            grid[y][x] = nextTarget;
            if (!changed)
              changed = true;
          }
        }
      }
    }
    return changed;
  }
};
