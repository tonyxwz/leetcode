#include "leetcode.h"

// dynamic programming
class Solution1
{
public:
  vector<vector<string>> partition(string s)
  {

    auto is_palin = [](const string& str) -> bool {
      for (int i = 0, n_ = str.length(); i < n_ / 2; ++i)
        if (str[i] != str[n_ - i - 1])
          return false;
      return true;
    };

    const int n = s.length();
    // dp[i] := partition schemes using first n chars
    vector<vector<vector<string>>> dp(n + 1);

    for (int i = 1; i <= n; ++i) {  // using first n characters
      for (int j = 0; j < i; ++j) { // start of substr
        string right = s.substr(j, i - j);
        if (!is_palin(right))
          continue;
        if (j == 0)
          dp[i].push_back({ right });
        for (const auto& p : dp[j]) {
          dp[i].push_back(p);
          dp[i].back().push_back(right);
        }
      }
    }
    return dp.back();
  }
};

// dfs
class Solution2
{
public:
  vector<vector<string>> partition(string s)
  {
    auto is_palin = [](const string& str) -> bool {
      for (int i = 0, n_ = str.length(); i < n_ / 2; ++i)
        if (str[i] != str[n_ - i - 1])
          return false;
      return true;
    };

    vector<vector<string>> ans;
    vector<string> curr;

    function<void(int)> dfs = [&](int l) { // used `l` characters
      if (l == s.length()) {
        ans.push_back(curr);
        return;
      }
      for (int i = l; i < s.length(); i++) {
        string right = s.substr(l, i - l + 1);
        if (!is_palin(right))
          continue;
        curr.push_back(right);
        dfs(l + right.length());
        curr.pop_back();
      }
    };
    dfs(0);
    return ans;
  }
};

// dfs
