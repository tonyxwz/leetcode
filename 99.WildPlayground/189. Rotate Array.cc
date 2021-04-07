#include "leetcode.h"

// Stupid method
class Solution
{
public:
  void rotate(vector<int>& nums, int k)
  {
    int n = nums.size();
    k = k % n; // 0 <= k < n;
    bool rev = false;
    if (k > n - k) {
      rev = true;
      k = n - k;
      reverse(nums.begin(), nums.end());
    }
    reverse(nums.begin(), nums.end() - k);
    for (int i = 0; i < k; ++i)
      swap(nums[i], nums[n - k + i]);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin() + k, nums.end() - k);
    if (rev)
      reverse(nums.begin(), nums.end());
  }
};

// is basically the same idea as
class Solution
{
public:
  void rotate(vector<int>& nums, int k)
  {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.begin() + k);
  }
};