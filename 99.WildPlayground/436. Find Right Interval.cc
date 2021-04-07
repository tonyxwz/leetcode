#include "leetcode.h"

class Solution
{
public:
  vector<int> findRightInterval(vector<vector<int>>& intervals)
  {
    vector<int> idx(intervals.size());
    iota(idx.begin(), idx.end(), 0);

    auto myless = [&](const int& a, const int& b) {
      return intervals[a][0] < intervals[b][0];
    };
    sort(idx.begin(), idx.end(), myless);

    vector<int> ans;
    auto cmp = [&](int j, int end_i) { return intervals[j][0] < end_i; };
    for (int i = 0; i < intervals.size(); ++i) {
      auto it = lower_bound(idx.begin(), idx.end(), intervals[i][1], cmp);
      if (it == idx.end())
        ans.push_back(-1);
      else
        ans.push_back(*it);
    }
    return ans;
  }
};
