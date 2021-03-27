#include "leetcode.h"

class Solution
{
public:
  int countSquares(vector<vector<int>>& M)
  {
    const int m = M.size();
    const int n = M[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (M[i][j]) {
          dp[i][j] = (j == 0 ? 1 : dp[i][j - 1] + 1);

          int narrow = INT_MAX;
          for (int k = i; k >= 0; --k) {
            int e = i - k + 1; // edge of the square to search
            narrow = min(narrow, dp[k][j]);
            if (narrow < e)
              break;
            ans++;
          }
        }
      }
    }

    return ans;
  }
};
