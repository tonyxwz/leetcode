#include "leetcode.h"

class Solution
{
public:
  int strangePrinter(string s)
  {
    const int n = s.length();
    vector<vector<int>> memo(n, vector<int>(n, 0));
    return dp(s, 0, n - 1, memo);
  }

  int dp(const string& s, int i, int j, vector<vector<int>>& memo)
  {
    if (i > j)
      return 0;
    // cout << i << ", "<< j << endl;
    if (memo[i][j] == 0) {
      int ans = dp(s, i + 1, j, memo) + 1;
      for (int k = i + 1; k <= j; ++k) {
        if (s[k] == s[i])
          ans = min(ans, dp(s, i, k - 1, memo) + dp(s, k + 1, j, memo));
      }
      memo[i][j] = ans;
    }
    return memo[i][j];
  }
};
