#include "leetcode.h"

class Solution
{
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<State> states(graph.size(), UNKNOWN);
    vector<int> safeNodes;
    for(int i = 0; i < graph.size(); ++i) {
      if (dfs(graph, i, states) == SAFE)
        safeNodes.push_back(i);
    }
    sort(begin(safeNodes), end(safeNodes));
    return safeNodes;
  }

private:
  enum State
  {
    UNKNOWN,
    VISITING,
    SAFE,
    UNSAFE
  };
  State dfs(const vector<vector<int>>& g, int curr, vector<State>& states)
  {
    // 如果访问的一个节点被标注为visiting，那么说明这个节点构成了环
    if (states[curr] == VISITING)
      return UNSAFE;
    if (states[curr] != UNKNOWN)
      return states[curr];
    states[curr] = VISITING;
    for (const auto c : g[curr])
      if (dfs(g, c, states) == UNSAFE)
        return states[curr] = UNSAFE;
    return states[curr] = SAFE;
  }
};

