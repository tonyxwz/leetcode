#include "leetcode.h"

// Array problems
// first fill the array with the product of the number in the left
// then multiply the elements with the product of the numbers in the right

class Solution
{
public:
  vector<int> productExceptSelf(vector<int>& nums)
  {
    const int n = nums.size();
    vector<int> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; ++i) {
      ans[i] = ans[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; --i) {
      ans[i] *= right;
      right *= nums[i];
    }
    return ans;
  }
};