#include "leetcode.h"

class Solution
{
private:
  map<char, char> parents_;
  char find(char x)
  {
    while (parents_[x] != x) {
      parents_[x] = parents_[parents_[x]];
      x = parents_[x];
    }
    return parents_[x];
  }
  void union_(char a, char b) { parents_[find(a)] = parents_[find(b)]; }

public:
  bool equationsPossible(vector<string>& equations)
  {
    parents_.clear();
    for (const auto& s : equations)
      if (s.substr(1, 2) == "==") {
        if (parents_.count(s[0]) == 0)
          parents_[s[0]] = s[0];
        if (parents_.count(s[3]) == 0)
          parents_[s[3]] = s[3];
        union_(s[0], s[3]);
      }
    for (const auto& s : equations) {
      if (s.substr(1, 2) == "!=") {
        auto a = s[0], b = s[3];
        if (a == b ||
            (parents_.count(a) && parents_.count(b) && find(a) == find(b))) {
          return false;
        }
      }
    }
    return true;
  }
};