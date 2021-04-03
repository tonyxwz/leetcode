#include "leetcode.h"

/*
                   *
                 *
begin  *       *
  -> *   *   * <- end
    *      *
  *

起始点：从右向左 找到最后一个比右边的最小值大的坐标
结束点：从左向右 找到最后一个比左边的最大值小的坐标
*/
class Solution
{
public:
  int findUnsortedSubarray(vector<int>& nums)
  {
    const int n = nums.size();
    int m = INT_MAX, M = INT_MIN;
    int beg = 1, end = 0;
    for (int i = 0; i < n; ++i) {
      m = min(m, nums[n - i - 1]);
      M = max(M, nums[i]);
      if (nums[n - i - 1] > m)
        beg = n - i - 1;
      if (nums[i] < M)
        end = i;
    }
    return end - beg + 1;
  }
};

class Solution2
{
public:
  int findUnsortedSubarray(vector<int>& nums)
  {
    const int n = nums.size();
    int l = n, r = 0;
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && nums[s.top()] > nums[i]) {
        l = min(l, s.top());
        s.pop();
      }
      s.push(i);
    }
    s = {};
    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && nums[s.top()] < nums[i]) {
        r = max(r, s.top());
        s.pop();
      }
      s.push(i);
    }
    return r > l ? r - l + 1 : 0;
  }
};

// brutal force
class Solution3
{
public:
  int findUnsortedSubarray(vector<int>& nums)
  {
    const int n = nums.size();
    int l = nums.size(), r = 0;
    for (int i = 0; i < n; ++i) {
      int t = i;
      for (int j = i + 1; j < n; ++j) {
        if (nums[i] > nums[j]) {
          l = min(l, i);
          r = max(r, j);
        }
      }
    }
    return l > r ? 0 : r - l + 1;
  }
};
