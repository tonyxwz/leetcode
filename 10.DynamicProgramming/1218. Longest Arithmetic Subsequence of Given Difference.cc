#include "leetcode.h"
class Solution
{
public:
  int longestSubsequence(vector<int>& arr, int difference)
  {
    // longest subsequence ending with arr[i]
    unordered_map<int, int> dp;
    int ans = 0;
    for (int i : arr) {
      dp[i] = dp[i - difference] + 1;
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
