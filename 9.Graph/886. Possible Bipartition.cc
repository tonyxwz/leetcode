#include "leetcode.h"

class Solution
{
private:
  bool paint(int node,
             int color,
             const vector<vector<int>>& g,
             vector<int>& colors)
  {
    if (colors[node])
      return colors[node] == color;
    colors[node] = color;
    for (const auto n : g[node])
      if (!paint(n, color == 1 ? 2 : 1, g, colors))
        return false;
    return true;
  }

public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes)
  {
    vector<vector<int>> g(N + 1);
    vector<int> colors(N + 1, 0); // 0 for unvisited
    for (const auto& d : dislikes) {
      g[d[0]].push_back(d[1]);
      g[d[1]].push_back(d[0]);
    }
    for (int i = 1; i <= N; ++i)
      if (!colors[i])
        if (!paint(i, 1, g, colors))
          return false;
    return true;
  }
};