#include "leetcode.h"

class Solution
{
public:
  int countNegatives(vector<vector<int>>& grid)
  {
    // vector<int> zero{0, 0};
    auto it = upper_bound(
      grid.begin(),
      grid.end(),
      vector<int>{ 0 },
      [](const vector<int>& a, const vector<int>& b) { return a[0] > b[0]; });
    int ans = (grid.end() - it) * grid[0].size();
    // cout << ans << endl;
    for (auto i = grid.begin(); i != it; ++i) {
      auto it_ = upper_bound(i->begin(), i->end(), 0, greater<int>());
      ans += i->end() - it_;
    }
    return ans;
  }
};