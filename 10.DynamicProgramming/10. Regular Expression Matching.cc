#include "leetcode.h"

// Note: dp[i][j]: s[:i] matches pattern p[:j]

class Solution
{
public:
  bool isMatch(string s, string p)
  {
    const int n1 = s.length(), n2 = p.length();
    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] = dp[i][j - 2] || // no repeat
                     (i && dp[i - 1][j] &&
                      (p[j - 2] == '.' || p[j - 2] == s[i - 1])); // >= 1 repeat
        } else {
          dp[i][j] = // matching character or wild card
            i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
      }
    }
    return dp[n1][n2];
  }
};
