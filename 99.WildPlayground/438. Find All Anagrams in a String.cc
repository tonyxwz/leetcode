#include "leetcode.h"

class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    vector<int> m1(26), m2(26), ans;
    for (auto c : p)
      m1[c - 'a']++;

    for (int i = 0, n = s.length(), l = p.length(); i < n; ++i) {
      m2[s[i] - 'a']++;
      if (i >= l)
        m2[s[i - l] - 'a']--;

      if (m1 == m2)
        ans.push_back(i - l + 1);
    }
    return ans;
  }
};