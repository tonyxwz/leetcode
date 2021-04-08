#include "leetcode.h"

// naive brutal force method
class Solution
{
public:
  vector<int> findSubstring(string s, vector<string>& words)
  {
    unordered_map<string, int> w;
    for (const auto& w_ : words)
      w[w_]++;
    vector<int> ans;
    // string_view s_(s);
    int m = s.length(), n = words[0].length(), tar_len = n * words.size();
    for (int i = 0; i <= m - tar_len; ++i) {
      int j = 0;
      unordered_map<string, int> seen;
      for (int k = i; j < words.size(); j++, k += n) {
        auto subs = s.substr(k, n);
        if (!w.count(subs))
          break;
        seen[subs]++;
        if (seen[subs] > w[subs])
          break;
      }
      if (j == words.size())
        ans.push_back(i);
    }
    return ans;
  }
};