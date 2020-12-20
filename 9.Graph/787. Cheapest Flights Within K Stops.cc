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
      if (steps++ > K)
        break;
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

// solution2 bellman-ford
