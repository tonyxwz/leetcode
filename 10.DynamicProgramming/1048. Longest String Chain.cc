#include "leetcode.h"
// Sigh! At least it works
// dp[i]: the length of longest string chain ending with words[i]
class Solution
{
public:
  int longestStrChain(vector<string>& words)
  {
    auto len = [](const string& a, const string& b) {
      return a.length() < b.length();
    };

    sort(words.begin(), words.end(), len);

    const int n = words.size();
    size_t l = INT_MAX, r = 0;

    vector<vector<int>> wl(17);

    for (int i = 0; i < n; ++i) {
      wl[words[i].length()].push_back(i);
      l = min(l, words[i].length());
      r = max(r, words[i].length());
    }

    auto is_pred = [](const string& pre, const string& post) {
      const int L = pre.length(); // length of substr
      for (int l = 0; l <= L; ++l) {
        if (pre == (post.substr(0, l) + post.substr(l + 1, L - l))) {
          return true;
        }
      }
      return false;
    };

    vector<int> dp(n, 1); // length of string chain ending with words[i]
    for (int i = 0; i < n; ++i) {
      if (words[i].length() == l)
        continue;
      for (const int j : wl[words[i].length() - 1]) {
        if (is_pred(words[j], words[i])) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};
