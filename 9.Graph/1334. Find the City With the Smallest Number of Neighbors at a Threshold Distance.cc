#include "leetcode.h"

// all pairs shortest path
// floyd warshall

class Solution
{
public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
  {
    // Matrix
    vector<vector<int>> M(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; ++i)
      M[i][i] = 0;
    for (const auto& e : edges)
      M[e[0]][e[1]] = M[e[1]][e[0]] = e[2];

    // Floyd-Warshall, x: proxy node
    for (int x = 0; x < n; ++x) {
      for (int u = 0; u < n; ++u) {
        if (u == x || M[u][x] == INT_MAX)
          continue;
        for (int v = 0; v < n; ++v) {
          if (v == x || M[x][v] == INT_MAX)
            continue;
          if (M[u][v] > M[u][x] + M[x][v]) // relax if find a better route
            M[u][v] = M[u][x] + M[x][v];
        }
      }
    }

    int ans = 0;
    int num_reachable = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int _num = 0;
      for (const auto d : M[i])
        if (d <= distanceThreshold)
          _num++;
      if (_num <= num_reachable) {
        ans = i;
        num_reachable = _num;
      }
    }
    return ans;
  }
};
