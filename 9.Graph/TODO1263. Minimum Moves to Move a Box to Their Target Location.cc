#include "leetcode.h"
class Solution
{
public:
  using coord = pair<int, int>;
  int minPushBox(vector<vector<char>>& grid)
  {
    m = grid.size();
    n = grid[0].size();
    int Tx, Ty, Sx, Sy, Bx, By;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 'T') {
          Ty = j; // Target
          Tx = i;
        } else if (grid[i][j] == 'B') {
          By = j; // box
          Bx = i;
        } else if (grid[i][j] == 'S') {
          Sy = j; // player
          Sx = i;
        }
      }
    }

    // distance, y, x
    priority_queue<tuple<int, int, int>,
                   vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
      q; // min heap

    int ans = INT_MAX;
    q.emplace(0, By, Bx); // push the box into the queue
    while (!q.empty()) {
      int qsize = q.size();
      while (qsize--) {
        int d = get<0>(q.top());
        int y = get<1>(q.top());
        int x = get<2>(q.top());
        q.pop();

        if (Ty == y && Tx == x)
          return d;
        for (int i = 0; i < 4; ++i) {
          int y_ = y + dirs[i];
          int x_ = x + dirs[i + 1];
          int y_push = y - dirs[i];
          int x_push = x - dirs[i + 1];

          if (y_push < 0 || y_push >= m || x_push < 0 || x_push >= n ||
              grid[y_push][x_push] != '.') {
          }
        }
      }
    }
    return -1;
  }

private:
  int m;
  int n;
  inline static const int dirs[5] = { 0, -1, 0, 1, 0 };

  int walk(coord from, coord to, const vector<vector<char>>& grid)
  {
    if (grid[to.first][to.second] != '.')
      return -1;
    if (to == from)
      return 0;

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<coord> q;
    int steps = 0;
    q.push(from);

    while (!q.empty()) {
      int qsize = q.size();
      while (qsize--) {
        coord u = q.front();
        q.pop();
        if (u == to)
          return steps;
        visited[u.first][u.second] = true;
        for (int i = 0; i < 4; ++i) {
          int y = u.first + dirs[i];
          int x = u.second + dirs[i + 1];
          if (y < 0 || y >= m || x < 0 || x >= n)
            continue;
          if (!visited[y][x] && grid[y][x] == '.')
            q.emplace(y, x);
        }
      }
      ++steps;
    }
    return -1;
  }
};