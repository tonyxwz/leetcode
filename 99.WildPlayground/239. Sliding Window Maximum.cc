#include "leetcode.h"

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k)
  {
    deque<int> q;
    const int n = nums.size();
    vector<int> ans(n - k + 1);

    for (int i = 0; i < n; ++i) {
      while (!q.empty() && q.front() < i - k + 1)
        q.pop_front();
      while (!q.empty() && nums[q.back()] <= nums[i])
        q.pop_back();
      q.push_back(i);
      if (i - k + 1 >= 0)
        ans[i - k + 1] = nums[q.front()];
    }
    return ans;
  }
};
