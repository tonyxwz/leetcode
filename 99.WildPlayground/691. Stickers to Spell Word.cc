#include "leetcode.h"
// Note: DFS with memoization

class Solution
{
public:
  int minStickers(vector<string>& stickers, string target)
  {
    vector<vector<int>> stkrs(stickers.size(), vector<int>(26, 0));
    for (int i = 0; i < stickers.size(); ++i)
      for (const auto c : stickers[i])
        stkrs[i][c - 'a']++;
    unordered_map<string, int> dp;
    dp[""] = 0;
    return dfs(target, dp, stkrs);
  }

  int dfs(string s,
          unordered_map<string, int>& dp,
          const vector<vector<int>>& stickers)
  {
    if (dp.count(s))
      return dp[s];
    cout << s << endl;
    vector<int> letters(26, 0);
    for (auto c : s)
      letters[c - 'a']++;

    int ans = INT_MAX;

    for (const auto& st : stickers) {
      if (st[s[0] - 'a'] == 0)
        continue; // proning
      string s_;
      for (int i = 0; i < 26; ++i)
        if (letters[i] - st[i] > 0)
          s_ += string(letters[i] - st[i], i + 'a');
      int tmp = dfs(s_, dp, stickers);
      if (tmp != -1)
        ans = min(ans, tmp + 1);
    }

    dp[s] = (ans == INT_MAX ? -1 : ans);
    return dp[s];
  }
};