#include "leetcode.h"

// Note: It's better to use Stack
class Solution
{
public:
  string decodeString(string str)
  {
    stack<pair<string, int>> s;
    string curr;
    int n = 0;
    for (auto c : str) {
      if (isdigit(c)) {
        n = n * 10 + c - '0';
      } else if (c == '[') {
        s.push({ curr, n });
        curr.clear();
        n = 0;
      } else if (c == ']') {
        auto prefix = s.top().first;
        n = s.top().second;
        s.pop();
        while (n--)
          prefix += curr;
        curr.swap(prefix);
        n = 0;
      } else {
        curr.push_back(c);
      }
    }
    return curr;
  }

  string decodeString2(string s)
  {
    int i = 0;
    return decodeString(s, i);
  }

  string decodeString(const string& s, int& i)
  {
    string res;
    while (i < s.length() && s[i] != ']') {
      if (!isdigit(s[i])) {
        res.push_back(s[i++]);
      } else {
        int n = 0;
        while (isdigit(s[i])) {
          n = n * 10 + s[i] - '0';
          i++;
        }
        // [
        i++;
        string rep = decodeString(s, i);
        while (n--)
          res += rep;
        i++;
      }
    }
    return res;
  }
};
