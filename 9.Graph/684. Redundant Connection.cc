#include "leetcode.h"

// Reminder: find cycle in graph
class Solution
{
  // DFS brute force
  // for each edges [u, v], find a path that connects u to v
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges)
  {
    unordered_map<int, vector<int>> g;
    for (const auto& e : edges) {
      unordered_set<int> visited;
      if (dfs(e[0], e[1], g, visited))
        return e;
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    return {};
  }

private:
  bool dfs(const int source,
           const int target,
           const unordered_map<int, vector<int>>& g,
           unordered_set<int>& seen)
  {
    if (source == target)
      return true;
    seen.insert(source);
    if (!g.count(source) || !g.count(target))
      return false;
    for (const auto& e : g.at(source)) {
      if (seen.count(e))
        continue;
      if (dfs(e, target, g, seen))
        return true;
    }
    return false;
  }
};

// Union find
class DisjointSet
{
public:
  // The size of the input 2D-array will be between 3 and 1000.
  // *Every integer represented in the 2D-array will be between 1 and N, where N
  // is the size of the input array.*
  DisjointSet(int N)
    : parents(N + 1, 0)
    , rank(N + 1, 0)
    , size(N + 1, 1)
  /* , n_sets(N) */
  {
    for (int i = 0; i < parents.size(); i++) {
      parents[i] = i;
    }
  }

  bool UnionSet(int a, int b)
  {
    int pa = FindSet(a);
    int pb = FindSet(b);
    if (pa == pb)
      return false;
    if (rank[pa] < rank[pb])
      parents[pa] = pb;
    else if (rank[pa] > rank[pb])
      parents[pb] = pa;
    else {
      parents[pb] = pa;
      rank[pa]++;
    }
    return true;
  }

  int FindSet(int x)
  {
    if (x != parents[x])
      parents[x] = FindSet(parents[x]);
    return parents[x];
  }

private:
  vector<int> parents;
  vector<int> rank;
  vector<int> size;
  /* int n_sets; */
};

class Solution2
{
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges)
  {
    DisjointSet s(edges.size());
    for (const auto& e : edges)
      if (!s.UnionSet(e[0], e[1]))
        return e;
    return {};
  }
};

class Solution3
{
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges)
  {
    vector<int> parents(edges.size() + 1, 0);
    vector<int> size(edges.size() + 1, 0);

    for (const auto& e : edges) {
      int u = e[0];
      int v = e[1];
      if (!parents[u])
        parents[u] = u;
      if (!parents[v])
        parents[v] = v;
      int pu = find(u, parents);
      int pv = find(v, parents);
      if (pu == pv)
        return e;
      // merge pu and pv class
      if (size[pu] < size[pv])
        swap(pu, pv);
      parents[pv] = pu;
      size[pu] += size[pv];
    }
    return {};
  }

private:
  int find(int x, vector<int>& parents)
  {
    // x 不是根節點才能進入循環
    while (parents[x] != x) {
      parents[x] = parents[parents[x]];
      x = parents[x];
    }
    return x;
  }
};
