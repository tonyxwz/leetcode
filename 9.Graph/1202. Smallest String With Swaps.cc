#include "leetcode.h"

/*
 * Connected Components
 * 1) DFS, 2) Union-find
 *
 * find the character indices belonging to the one group, sort this group and
 * put the chars back to place.
 *
 * Again, union-find set is a nature solution for this sort of problems.
 *
 * Embedded version Unionfind
 * */

class Solution
{
public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
  {
    vector<int> parents(s.length(), 0);
    vector<int> ranks(s.length(), 0);
    for (int i = 0; i < parents.size(); ++i)
      parents[i] = i;

    function<int(int)> find = [&](int x) {
      if (parents[x] != x)
        parents[x] = find(parents[x]);
      return parents[x];
    };

    for (const auto& p : pairs)
      /* union_(p[0], p[1]); */
      parents[find(p[0])] = find(p[1]);

    vector<vector<int>> idx(s.length());
    vector<string> ss(s.length());
    for (int i = 0; i < s.length(); ++i) {
      const int id = find(i);
      idx[parents[id]].push_back(i); // already sorted
      ss[parents[id]].push_back(s[i]);
    }
    for (int i = 0; i < s.length(); ++i) {
      sort(begin(ss[i]), end(ss[i]));
      for (int j = 0; j < ss[i].length(); ++j)
        s[idx[i][j]] = ss[i][j];
    }
    return s;
  }
};

class Solution2
{
public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
  {
    vector<vector<int>> g(s.length());
    for (const auto& p : pairs) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    unordered_set<int> visited;
    vector<int> indices;
    string tmp;

    function<void(int)> dfs = [&](int x) {
      if (visited.count(x))
        return;
      visited.insert(x);
      indices.push_back(x);
      tmp.push_back(s[x]);
      for (const int n : g[x])
        dfs(n);
    };

    for (int i = 0; i < g.size(); ++i) {
      if (visited.count(i))
        continue;
      indices.clear();
      tmp.clear();
      /* dfs(i, g, s, indices, tmp, visited); */
      dfs(i);
      sort(begin(indices), end(indices));
      sort(begin(tmp), end(tmp));
      for (int j = 0; j < indices.size(); ++j)
        s[indices[j]] = tmp[j];
    }
    return s;
  }

private:
  void dfs2(int x,
            const vector<vector<int>>& g,
            const string& s,
            vector<int>& indices,
            string& tmp,
            unordered_set<int>& visited)
  {
    if (visited.count(x))
      return;
    visited.insert(x);
    indices.push_back(x);
    tmp.push_back(s[x]);
    for (const int n : g[x])
      dfs2(n, g, s, indices, tmp, visited);
  }
};
