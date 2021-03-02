#include "leetcode.h"

// Dijkstra
class Solution
{
public:
  double maxProbability(int n,
                        vector<vector<int>>& edges,
                        vector<double>& succProb,
                        int start,
                        int end)
  {
    vector<vector<pair<int, double>>> G(n);
    for (int i = 0; i < edges.size(); ++i) {
      const auto& e = edges[i];
      G[e[0]].emplace_back(e[1], succProb[i]);
      G[e[1]].emplace_back(e[0], succProb[i]);
    }
    vector<double> probs(n, 0.0);
    vector<bool> visited(n, false);
    priority_queue<pair<double, int>> pq; // max heap
    pq.emplace(1.0, start);

    while (!pq.empty()) {
      auto u = pq.top().second;
      auto p = pq.top().first;
      pq.pop();
      if (visited[u])
        continue;
      visited[u] = true;
      probs[u] = p;
      if (u == end)
        break;
      for (const auto& vp : G[u]) {
        const auto& v = vp.first;
        const auto& p2 = vp.second;
        auto p_ = p * p2;
        if (probs[v] < p_) {
          pq.emplace(p_, v);
        }
      }
    }
    return probs[end];
  }
};