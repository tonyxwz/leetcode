#include "leetcode.h"

/* Reminder:
Always think of DFS problems as Graph traversal, the problem then becomes
different choises when going to the next level.

TODO: use closure because `dfs` is a procedure only make sense inside `permute`
 */
class Solution
{
  void dfs(vector<int>& nums,
           vector<vector<int>>& ans,
           vector<int>& curr,
           vector<int>& used,
           int d)
  {
    if (d == nums.size()) {
      ans.push_back(curr);
    }
    for (int i = 0; i < nums.size(); i++) {
      if (used[i])
        continue;
      used[i] = 1;
      curr.push_back(nums[i]);
      dfs(nums, ans, curr, used, d + 1);
      curr.pop_back();
      used[i] = 0;
    }
  }

public:
  vector<vector<int>> permute(vector<int>& nums)
  {
    vector<vector<int>> ans;
    vector<int> curr;
    vector<int> used(nums.size());

    dfs(nums, ans, curr, used, 0);
    return ans;
  }
};