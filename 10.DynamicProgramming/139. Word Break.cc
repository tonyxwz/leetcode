#include "leetcode.h"

class Solution
{
public:
  bool wordBreak(string s, vector<string>& wordDict)
  {
    vector<bool> dp(s.length() + 1, false);

    dp[0] = true;
    for (int i = 1, n = s.length(); i <= n; ++i) {
      for (const auto& sub : wordDict) {
        if (i < sub.length())
          continue;
        if (dp[i - sub.length()] &&
            s.substr(i - sub.length(), sub.length()) == sub) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp.back();
  }
};
