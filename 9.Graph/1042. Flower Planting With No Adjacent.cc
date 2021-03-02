#include "leetcode.h"

// You have n gardens, labeled from 1 to n, and an array paths where paths[i] =
// [xi, yi] describes a bidirectional path between garden xi to garden yi. In
// each garden, you want to plant one of 4 types of flowers.

// All gardens have at most 3 paths coming into or leaving it.

// Your task is to choose a flower type for each garden such that, for any two
// gardens connected by a path, they have different types of flowers.

// Return any such a choice as an array answer, where answer[i] is the type of
// flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3,
// or 4. It is guaranteed an answer exists.

class Solution
{
public:
  vector<int> gardenNoAdj(int n, vector<vector<int>>& paths)
  {
    vector<vector<int>> g(n + 1);
    for (const auto& p : paths) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }                      // build graph
    vector<int> ans(n, 0); // 0 for no choice
    for (int i = 1; i <= n; ++i)
      if (ans[i - 1] == 0)
        plant(i, ans, g);
    return ans;
  }

private:
  int plant(int garden, vector<int>& ans, const vector<vector<int>>& g)
  {
    if (ans[garden - 1] != 0) {
      return ans[garden - 1];
    }
    cout << garden << ": " << ans[garden - 1] << endl;
    set<int> options{ 1, 2, 3, 4 };
    for (const auto n : g[garden]) {
      if (ans[n-1] != 0)
        options.erase(ans[n-1]);
    }
    ans[garden - 1] = *options.begin();
    return *options.begin();
  }
};

int
main()
{
  vector<vector<int>> paths{ { 1, 2 }, { 2, 3 }, { 3, 1 } };
  Solution sol;
  auto ans = sol.gardenNoAdj(3, paths);
  return 0;
}