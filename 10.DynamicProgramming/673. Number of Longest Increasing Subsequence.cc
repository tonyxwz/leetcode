#include "leetcode.h"

class Solution
{
public:
  int findNumberOfLIS(vector<int>& nums)
  {
    const int n = nums.size();
    vector<int> l(n, 1); // the length of LIS ending with nums[i]
    vector<int> c(n, 1); // number of LIS ending with nums[i]

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          if (l[i] < l[j] + 1) {
            // 如果经过 nums[j]，并以 nums[i] 结尾的子序列比已知的长，那么更新当前的长度
            // 以 nums[i] 长度为 l[i]，最长子序列数量是 c[j]
            l[i] = l[j] + 1;
            c[i] = c[j];
          } else if (l[i] == l[j] + 1) {
            // 如果以nums[j] 和 nums[i] 结尾的最长子序列长度等于已知的长度，那么可以更新
            // 以nums[i]结尾的最长子序列的数量
            c[i] += c[j];
          }
        }
      }
    }

    int max_len = *max_element(l.begin(), l.end());
    int ans = 0;
    for (int i = 0; i < n; ++i)
      if (l[i] == max_len)
        ans += c[i];
    return ans;
  }
};
