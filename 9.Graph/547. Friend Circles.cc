#include "leetcode.h"

class Solution
{
public:
  int findCircleNum(vector<vector<int>>& M)
  {
    if (M.empty())
      return 0;

    const auto N = M.size();
    vector<bool> visited(N, false);
    int ans = 0;

    for (int i = 0; i < N; ++i) {
      if (visited[i])
        continue;
      dfs(M, N, visited, i);
      ans++;
    }
    return ans;
  }

private:
  // dfs
  void dfs(const vector<vector<int>>& M,
           const int& N,
           vector<bool>& visited,
           int i)
  {
    if (visited[i])
      return;
    visited[i] = true;

    for (int j = 0; j < N; ++j) {
      if (M[j][i] && !visited[j])
        dfs(M, N, visited, j);
    }
  }
};

class DisjointSet
{
private:
  vector<int> parents;
  vector<int> ranks;

public:
  DisjointSet(const size_t N);
  int find(const int);
  bool union_(const int u, const int v);
};

DisjointSet::DisjointSet(const size_t N)
{
  parents = vector<int>(N + 1, 0);
  ranks = vector<int>(N + 1, 0);
  for (int i = 0; i < N + 1; ++i)
    parents[i] = i;
}

int
DisjointSet::find(const int u)
{
  if (u != parents[u])
    parents[u] = find(parents[u]);
  return parents[u];
}

bool
DisjointSet::union_(const int u, const int v)
{
  int pu = find(u);
  int pv = find(v);
  if (pu == pv)
    return false;
  if (ranks[pu] > ranks[pv]) {
    parents[pv] = pu;
  } else if (ranks[pu] < ranks[pv]) {
    parents[pu] = pv;
  } else {
    parents[pu] = pv;
    ranks[pv]++;
  }
  return true; // union'ed
}

class Solution2
{
public:
  int findCircleNum(vector<vector<int>>& M)
  {
    const int N = M.size();
    DisjointSet ds(N);
    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++)
        if (M[i][j])
          ds.union_(i, j);
    unordered_set<int> s;
    for (int i = 0; i < N; i++)
      s.insert(ds.find(i));
    return s.size();
  }
};
