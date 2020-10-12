#include "leetcode.h"

class Solution
{
  void dfs(vector<int>& candids,
           int target,
           vector<int>& curr,
           int start,
           vector<vector<int>>& ans)
  {
    if (target == 0) {
      ans.push_back(curr);
      return;
    }

    for (int i = start; i < candids.size(); i++) {
      if (candids[i] > target)
        break;
      // if repeated candidate exists: only consider the first one (since it is
      // sorted)
      if (i > start && candids[i] == candids[i - 1])
        continue;
      curr.push_back(candids[i]);
      dfs(candids, target - candids[i], curr, i + i, ans);
      curr.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
  {
    vector<int> curr;
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, curr, 0, ans);
    return ans;
  }
};