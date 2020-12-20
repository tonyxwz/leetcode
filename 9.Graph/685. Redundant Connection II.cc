#include "leetcode.h"

// organize the programme differently by implementing the disjoint set data
// structure inside the solution class

class Solution
{
private:
  int find(int x, vector<int>& d)
  {
    while (d[x] != x) {
      d[x] = d[d[x]];
      x = d[x];
    }
    return x;
  }

public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
  {
    const int N = edges.size();
    vector<int> p(N + 1, 0);

    // find the node with > 1 parents
    vector<int> ans1;
    vector<int> ans2;
    for (auto& e : edges) {
      int u = e[0];
      int v = e[1];
      if (p[v] > 0) {
        ans1 = { p[v], v };
        ans2 = e;
        // delete the latter edge
        e[0] = -1;
        e[1] = -1;
      } else {
        p[v] = u;
      }
    }

    vector<int> d(N + 1, 0);
    vector<int> sizes(N + 1, 1);
    // union-find
    for (const auto& e : edges) {
      // u -> v
      int u = e[0];
      int v = e[1];
      if (u < 0 && v < 0)
        continue;

      if (!d[u])
        d[u] = u;
      if (!d[v])
        d[v] = v;
      int pu = find(u, d);
      int pv = find(v, d);

      if (pu == pv) {
        // e is adding a cycle in the graph
        if (ans1.empty())
          return e; // there is no node with two parents
        else
          return ans1;
        // since `edges` no longer contains the second edge pointing to the
        // same node, if we are still able to find a cycle in the graph, then
        // it must be the first edge
      }
      // union by size
      if (sizes[pu] < sizes[pv])
        swap(pu, pv);
      d[pv] = pu;
      sizes[pu] += sizes[pv];
    }
    // 1. no cycle detected, return the latter of `ans1` `ans2`
    return ans2;
  }
};