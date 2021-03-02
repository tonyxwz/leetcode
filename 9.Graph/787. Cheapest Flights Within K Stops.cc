#include "leetcode.h"

class Solution
{
public:
  int findCheapestPrice(int n,
                        vector<vector<int>>& flights,
                        int src,
                        int dst,
                        int K)
  {
    // bfs
    unordered_map<int, vector<pair<int, int>>> g;
    for (const auto& f : flights)
      g[f[0]].emplace_back(f[1], f[2]);

    queue<pair<int, int>> q;
    q.push({ src, 0 });
    int ans = INT_MAX;
    int steps = 0;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        const int curr = q.front().first;
        const int cost = q.front().second;
        q.pop();
        if (curr == dst)
          ans = min(ans, cost);

        for (const auto& t : g[curr]) {
          const int v = t.first;
          const int cost_ = cost + t.second;
          if (cost_ > ans)
            continue;
          q.push({ v, cost_ });
        }
      }
      if (steps++ > K) // pruning part
        break;
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

// solution2 bellman-ford
// Note: What is the meaning of the relaxing the edges V-1 times?
// In a nice graph where there's no negative edges, it takes at most V-1 edges
// to go from src to dst.
// Outer loop is the number of edges of the route
class Solution2
{
public:
  int findCheapestPrice(int n,
                        vector<vector<int>>& flights,
                        int src,
                        int dst,
                        int K)
  {
    vector<int> cost(n, INT_MAX);
    cost[src] = 0;
    for (int i = 0; i <= K; i++) {
      //! important: keep a copy of the vector in last iteration,
      // meaning strictly limiting the number of steps
      vector<int> tmp(cost);
      for (const auto& f : flights) {
        const int u = f[0];
        const int v = f[1];
        const int cost_ = cost[u] == INT_MAX ? INT_MAX : cost[u] + f[2];
        tmp[v] = min(tmp[v], cost_);
      }
      cost.swap(tmp);
    }
    return cost[dst] == INT_MAX ? -1 : cost[dst];
  }
};