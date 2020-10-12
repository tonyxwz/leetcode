#include "leetcode.h"

/*Reminder:
1. sort: so that no need to process the candidates after the first invalid one
2. persist starting index: a candidate is only allowed to use the candidates
behind it self to construct combinations
 */
class Solution
{
  void dfs(const vector<int>& candidates,
           const int target,
           vector<int>& curr,
           int s,
           vector<vector<int>>& ans)
  {
    if (target == 0) {
      ans.push_back(curr);
      return;
    }
    for (int i = s; i < candidates.size(); i++) {
      if (candidates[i] > target)
        break;
      curr.push_back(candidates[i]);
      dfs(candidates, target - candidates[i], curr, i, ans);
      curr.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target)
  {
    vector<vector<int>> ans;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, curr, 0, ans);
    return ans;
  }
};