#include "leetcode.h"

class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval)
  {
    vector<vector<int>> ans;
    auto it = intervals.end();
    int i = -1; // i
    for (int i_ = 0; i_ < intervals.size(); ++i_) {
      if (intervals[i_][1] < newInterval[0]) {
        ans.push_back(intervals[i_]);
      } else {
        i = i_;
        break;
      }
    }

    int j = -1;
    for (int j_ = intervals.size() - 1; j_ >= 0; --j_) {
      if (intervals[j_][0] <= newInterval[1]) {
        j = j_;
        break;
      }
    }

    if (i >= 0)
      newInterval[0] = min(newInterval[0], intervals[i][0]);
    if (j >= 0)
      newInterval[1] = max(newInterval[1], intervals[j][1]);

    ans.push_back(newInterval);

    j++;
    while (j < intervals.size()) {
      ans.push_back(intervals[j]);
      j++;
    }
    return ans;
  }
};