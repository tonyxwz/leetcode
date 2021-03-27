#include "leetcode.h"

class Solution
{
public:
  bool isMatch(string s, string p)
  {
    const int m = s.length(), n = p.length();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;

    for (int i = 0; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] =
            (i && (dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1])) ||
            (i == 0 && dp[i][j - 1]);
        } else {
          dp[i][j] =
            i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
        }
      }
    }

    // for(int i = 0; i <= m; ++i) {
    //     cout << i << ":\t";
    //     for(int j = 0; j <= n; ++j)
    //         cout << dp[i][j] << ' ';
    //     cout << endl;
    // }

    return dp[m][n];
  }
};