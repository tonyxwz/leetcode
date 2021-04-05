#include "leetcode.h"

class Solution
{
public:
  string longestCommonPrefix(vector<string>& strs)
  {
    if (strs.empty())
      return "";
    size_t n = INT_MAX;
    for (const auto& s : strs)
      n = min(n, s.length());
    auto same_at = [&strs](int i) {
      const char c = strs[0][i];
      for (const auto& s : strs)
        if (s[i] != c)
          return false;
      return true;
    };
    int i = 0;
    for (; i < n; ++i) {
      if (!same_at(i))
        break;
    }
    return strs[0].substr(0, i);
  }
};