#include "leetcode.h"

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals)
  {
    auto fun = [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    };
    sort(intervals.begin(), intervals.end(), fun);
    auto range = intervals[0];
    vector<vector<int>> ans;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= range[1]) {
        // overlap
        range[1] = max(range[1], intervals[i][1]);
      } else {
        ans.push_back(range);
        range = intervals[i];
      }
    }
    ans.push_back(range);
    return ans;
  }
};