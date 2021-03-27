#include "leetcode.h"

class Solution
{
public:
  int rob(vector<int>& nums)
  {
    const int n = nums.size();
    int use = nums[0];
    int no_use = 0; //

    for (int i = 1; i < n; ++i) {
      int tmp = no_use;
      no_use = max(no_use, use);
      use = tmp + nums[i];
    }

    return max(use, no_use);
  }
};

// better
// Note: curr is the answer so far, pre is the answer of previous number.
//
class Solution
{
public:
  int rob(vector<int>& nums)
  {
    const int n = nums.size();

    int curr = 0, pre = 0;
    for (int i = 0; i < n; ++i) {
      int tmp = curr;
      curr = max(curr, pre + nums[i]);
      pre = tmp;
    }

    return curr;
  }
};
