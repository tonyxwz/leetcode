#include "leetcode.h"

// finding shortest path: use BFS-based traversal (most flexible)
// Dijkstra: for weighted problems

class Solution
{
public:
  vector<int> shortestAlternatingPaths(int n,
                                       vector<vector<int>>& red_edges,
                                       vector<vector<int>>& blue_edges)
  {
    vector<vector<int>> rg(n), bg(n);
    for (const auto& e : red_edges)
      rg[e[0]].push_back(e[1]);
    for (const auto& e : blue_edges)
      bg[e[0]].push_back(e[1]);

    vector<int> ans(n, -1);
    vector<bool> red_visited(n, false);
    vector<bool> blue_visited(n, false);

    // node, red?
    queue<pair<int, bool>> q;
    q.emplace(0, false);
    q.emplace(0, true);

    int step = 0;
    while (!q.empty()) {
      int qsize = q.size();
      while (qsize--) {
        int u = q.front().first;
        bool use_red = q.front().second;
        q.pop();
        cout << u << ": " << (use_red ? "red" : "blue") << endl;
        if (ans[u] == -1)
          ans[u] = step;
        else
          ans[u] = min(ans[u], step);

        if (use_red) {
          // rg
          if (red_visited[u])
            continue;
          red_visited[u] = true;
          for (const auto v : rg[u]) {
            if (!blue_visited[v])
              q.emplace(v, false);
          }
        } else {
          // bg
          if (blue_visited[u])
            continue;
          blue_visited[u] = true;
          for (const auto v : bg[u]) {
            if (!red_visited[v])
              q.emplace(v, true);
          }
        }
      }
      ++step;
    }
    return ans;
  }
};