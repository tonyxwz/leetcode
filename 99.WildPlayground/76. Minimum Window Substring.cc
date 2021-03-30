#include "leetcode.h"

class Solution
{
public:
  string minWindow(string s, string t)
  {
    unordered_map<char, int> m, ref;
    for (const auto c : t)
      ref[c]++;
    int required = ref.size(), filled = 0;

    int l = 0, r = 0; // r: excluding
    int p1 = -1, len = s.length();

    while (r <= s.length()) {
      // cout << l << " " << r << " " << s.substr(p1, len) << endl;
      if (filled == required) {
        if (len >= r - l) {
          len = r - l;
          p1 = l;
        }

        if (ref.count(s[l]) && m[s[l]] == ref.at(s[l]))
          filled--;
        m[s[l]]--;
        l++;
      } else {
        m[s[r]]++;
        if (ref.count(s[r]) && m[s[r]] == ref.at(s[r]))
          filled++;
        r++;
      }
    }

    return p1 >= 0 ? s.substr(p1, len) : "";
  }
};
