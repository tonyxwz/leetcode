#include "leetcode.h"

class Solution
{
public:
  string intToRoman(int num)
  {
    const vector<pair<int, string>> m{
      { 1, "I" },   { 4, "IV" },   { 5, "V" },   { 9, "IX" },  { 10, "X" },
      { 40, "XL" }, { 50, "L" },   { 90, "XC" }, { 100, "C" }, { 400, "CD" },
      { 500, "D" }, { 900, "CM" }, { 1000, "M" }
    };

    string ans;
    while (num) {
      for (auto p = m.crbegin(); p != m.crend(); ++p) {
        if (num >= p->first) {
          num -= p->first;
          ans += p->second;
          break;
        }
      }
    }
    return ans;
  }
};