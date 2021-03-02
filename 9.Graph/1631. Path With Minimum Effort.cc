#include "leetcode.h"

// Dijkstra
// Note: if the path in a graph will not be decrease, use Dijkstra

class Solution
{
public:
  int minimumEffortPath(vector<vector<int>>& heights)
  {
    using item = tuple<int, int, int>;
    const int rows = heights.size();
    const int cols = heights[0].size();
    vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    // efforts[0][0] = 0;

    const int dirs[] = { 0, -1, 0, 1, 0 };
    // min heap
    //            eff, row, col
    priority_queue<item, vector<item>, greater<item>> pq;
    pq.emplace(0, 0, 0);
    while (!pq.empty()) {
      auto eff = get<0>(pq.top());
      auto r = get<1>(pq.top());
      auto c = get<2>(pq.top());
      pq.pop();
      if (visited[r][c])
        continue;
      visited[r][c] = true;
      efforts[r][c] = eff;
      if (r == rows - 1 && c == cols - 1)
        break; // stop early
      for (int i = 0; i < 4; ++i) {
        auto r_ = r + dirs[i];
        auto c_ = c + dirs[i + 1];
        if (r_ < 0 || r_ >= rows || c_ < 0 || c_ >= cols)
          continue;
        int eff_ = max(eff, abs(heights[r][c] - heights[r_][c_]));
        if (!visited[r_][c_] && efforts[r_][c_] > eff_) {
          pq.emplace(eff_, r_, c_);
          efforts[r_][c_] = eff_;
        }
      }
    }
    return efforts[rows - 1][cols - 1];
  }
};