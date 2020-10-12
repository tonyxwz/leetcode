#include "leetcode.h"

// Reminder: permutation / DFS need to carefully devise the condition, wether to
// continue or not (Graph traversal)
class Solution
{
  void dfs(vector<int>& nums,
           vector<vector<int>>& ans,
           vector<int>& curr,
           vector<int>& used)
  {
    if (curr.size() == nums.size()) {
      ans.push_back(curr);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      /*当前这一位数字在前面的递归中已经被使用了*/
      if (used[i])
        continue;
      /* 对于每一位数字的，如果他等于前一位候选的数字，而且前一位数字没有被使用过，那么说明
      以当前数字为开始的组合已经被遍历过了。*/
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;
      used[i] = 1;
      curr.push_back(nums[i]);
      dfs(nums, ans, curr, used);
      curr.pop_back();
      used[i] = 0;
    }
  }

public:
  vector<vector<int>> permuteUnique(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> curr;
    vector<int> used(nums.size());

    dfs(nums, ans, curr, used);
    return ans;
  }
};