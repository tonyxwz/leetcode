#include "leetcode.h"

// Note: simple array questions

class Solution
{
public:
  vector<int> findDisappearedNumbers(vector<int>& nums)
  {
    int n = nums.size();
    vector<bool> appear(n + 1, false);
    for (int i = 0; i < n; ++i)
      appear[nums[i]] = true;
    vector<int> ans;
    for (int i = 1; i <= n; ++i)
      if (!appear[i])
        ans.push_back(i);
    return ans;
  }
};

// Follow up: O(1) extra storage
class Solution
{
public:
  vector<int> findDisappearedNumbers(vector<int>& nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      // if x is never 1, then nums[0] will never be negative
      int x = (nums[i] < 0 ? -nums[i] : nums[i]) - 1;
      nums[x] = nums[x] > 0 ? -nums[x] : nums[x];
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i)
      if (nums[i] > 0)
        ans.push_back(i + 1);
    return ans;
  }
};
