#include "leetcode.h"

// don't think too much

class Solution
{
public:
  int makeConnected(int n, vector<vector<int>>& connections)
  {
    if (connections.size() < n - 1)
      return -1;
    vector<int> parents(n);
    iota(parents.begin(), parents.end(), 0);

    auto find = [&parents](int x) -> int {
      while(x!=parents[x]) {
        parents[x] = parents[parents[x]];
        x = parents[x];
      }
      return parents[x];
    };

    for (const auto& c : connections)
      parents[find(c[0])] = parents[find(c[1])];
    unordered_set<int> m;
    for (int i = 0; i < n; ++i) {
      m.insert(find(i));
    }
    return m.size() - 1;
  }
};
