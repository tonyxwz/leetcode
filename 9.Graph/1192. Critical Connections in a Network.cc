#include "leetcode.h"

/*
  Tarjan's algorithm principles:
    perform dfs on the graph, assign each node a
      - timestamp: won't change after assigned
      - low-link value: the earliest timestamp of the nodes that current node
        can reach. Initially low-link value equals timestamp
  if low-link value of a node equals it's timestamp, those nodes on the visiting
  path, and whose low-link values equals this low-link value are a strongly
  connected component of the graph

  this problem doesn't requires the entire tarjan's algorithm because we only
  need to use tarjan to detect cycles
*/

class Solution
{
public:
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>>& connections)
  {
    vector<vector<int>> g(n);
    for (const auto& conn : connections) {
      g[conn[0]].push_back(conn[1]);
      g[conn[1]].push_back(conn[0]);
    }
    vector<vector<int>> ans;
    vector<int> id(n, -1), ll(n, 0);
    int curr = 0;
    for (int i = 0; i < n; ++i)
      if (id[i] < 0)
        dfs(i, -1, curr, g, ans, id, ll);
    return ans;
  }
  int dfs(int u,
          const int parent,
          int& curr,
          const vector<vector<int>>& g,
          vector<vector<int>>& ans,
          vector<int>& id,
          vector<int>& ll)
  {
    int min_u = id[u] = curr++;
    for (int v : g[u]) {
      if (id[v] < 0) { // unvisited
        int min_v = dfs(v, u, curr, g, ans, id, ll);
        min_u = min(min_u, min_v);
        if (id[u] < min_v) {
          ans.push_back({ u, v });
        }
      } else if (v != parent) {
        min_u = min(min_u, id[v]);
      }
    }
    return min_u;
  }
};

// for a undirected graph, an edge is critical if and only if it is not in a
// cycle

class Solution2
{
public:
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>>& connections)
  {
    vector<vector<int>> g(n);   // graph
    vector<int> ts(n, INT_MAX); // timestamp
    vector<vector<int>> ans;
    int t = 0;

    // curr, parent
    // return value: the lowest node that it can find
    //
    // if one child's lowest value is lower than its parent's, then it means
    // there's no cycle from parent to this child.

    function<int(int, int)> tarjan = [&](int i, int p) {
      int min_i = ts[i] = ++t; // assign a timestamp
      for (int j : g[i]) {
        if (ts[j] == INT_MAX) {      // child j is unvisited
          int min_j = tarjan(j, i);  // lowest of j's reachable element
          min_i = min(min_i, min_j); // update i's loweast reachable
          if (ts[i] < min_j) // if i's child j cannot reach a node lower than i,
                             // then i and j are not in a cycle, we should push
                             // edge {i, j} in the answer
            ans.push_back({ i, j });
        } else if (j != p) {
          // j is visited, and don't follow the path i <-> j
          // because g is a undirected graph
          min_i = min(min_i, ts[j]);
        }
      }
      return min_i;
    };

    for (const auto& e : connections) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    tarjan(0, -1);
    return ans;
  }
};