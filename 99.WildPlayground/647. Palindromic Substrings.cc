#include "leetcode.h"

class Solution
{
public:
  int countSubstrings(string s)
  {
    const int n = s.length();
    // dp[i][j] := substring starting from i, length j is a palindrome
    vector<vector<bool>> dp(n + 1, vector<bool>(n, true));

    int ans = 0;
    for (int l = 2; l <= n; ++l) {
      for (int i = 0; i <= n - l; ++i) {
        dp[l][i] = dp[l - 2][i + 1] && s[i] == s[i + l - 1];
        if (dp[l][i]) {
          ans++;
        }
      }
    }

    return ans + n;
  }
};
