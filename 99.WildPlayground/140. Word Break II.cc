#include "leetcode.h"

// TODO Trie
class Solution
{
public:
  vector<string> wordBreak(string s, vector<string>& wordDict)
  {
    size_t max_len = 0;
    size_t min_len = INT_MAX;
    unordered_set<string> S;

    for (const auto& s_ : wordDict) {
      S.insert(s_);
      max_len = max(max_len, s_.length());
      min_len = min(min_len, s_.length());
    }

    vector<string> brk;
    vector<string> ans;

    function<void(int)> dfs = [&](int i) {
      if (i == s.length()) {
        string res = brk[0];
        for (int i = 1; i < brk.size(); ++i)
          res += (" " + brk[i]);
        ans.push_back(res);
        return;
      }

      for (int l = min_len, k = min(max_len, s.length() - i); l <= k; ++l) {
        string s_ = s.substr(i, l);
        if (S.count(s_)) {
          brk.push_back(s_);
          dfs(i + l);
          brk.pop_back();
        }
      }
    };

    dfs(0);
    return ans;
  }
};