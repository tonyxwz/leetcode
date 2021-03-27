#include "leetcode.h"
class Solution
{
public:
  int minimumDeleteSum(string s1, string s2)
  {
    // dp[i][j] : maximum sum of common subsequence of s1[:i], s2[:j]
    const int l1 = s1.length(), l2 = s2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
    // dp[0][1] = s2[0], dp[1][0] = s1[0];

    for (int i = 1; i <= l1; ++i) {
      for (int j = 1; j <= l2; ++j) {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + s1[i - 1]);
      }
    }

    return accumulate(s1.begin(), s1.end(), 0) +
           accumulate(s2.begin(), s2.end(), 0) - 2 * dp[l1][l2];
  }
};