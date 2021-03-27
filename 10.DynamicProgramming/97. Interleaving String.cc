#include "leetcode.h"

class Solution1
{
public:
  bool isInterleave(string s1, string s2, string s3)
  {
    vector<set<pair<int, int>>> dp(s3.length() + 1);
    dp[0].insert({ 0, 0 });

    const int m = s1.length(), n = s2.length();

    for (int k = 1, ub = s3.length(); k <= ub; ++k) { // s3

      for (int i = 0; i <= m; ++i) {   // s1
        for (int j = 0; j <= n; ++j) { // s2
          if (i && s3[k - 1] == s1[i - 1])
            if (dp[k - 1].count({ i - 1, j }))
              dp[k].insert({ i, j });
          if (j && s3[k - 1] == s2[j - 1])
            if (dp[k - 1].count({ i, j - 1 }))
              dp[k].insert({ i, j });
        }
      }
    }

    return dp[s3.length()].count({ s1.length(), s2.length() });
  }
};

class Solution2
{
public:
  bool isInterleave(string s1, string s2, string s3)
  {
    const int m = s1.length(), n = s2.length();

    if (m + n != s3.length())
      return false;
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        int start = i + j;
        if (start == 0)
          continue;
        if (i && s3[start - 1] == s1[i - 1])
          dp[i][j] = dp[i][j] || dp[i - 1][j];
        if (j && s3[start - 1] == s2[j - 1])
          dp[i][j] = dp[i][j] || dp[i][j - 1];
      }
    }

    return dp[m][n];
  }
};
