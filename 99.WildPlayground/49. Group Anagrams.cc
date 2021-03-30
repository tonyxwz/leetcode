#include "leetcode.h"

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs)
  {
    unordered_map<string, int> m;
    vector<vector<string>> ans;

    for (const auto& s : strs) {
      auto key = s;
      sort(key.begin(), key.end());
      if (!m.count(key)) {
        m[key] = ans.size();
        ans.push_back({});
      }
      ans[m.at(key)].push_back(s);
    }

    return ans;
  }
};