#include "leetcode.h"

class Solution
{
public:
  string simplifyPath(string path)
  {
    stack<string> s;
    int i = 0;
    while (i < path.length()) {
      while (i < path.length() && path[i] == '/')
        i++;
      int j = i;
      while (i < path.length() && (path[i] != '/'))
        i++;
      // cout << i << endl;
      string x = path.substr(j, i - j);
      if (x == "." || x == "")
        continue;
      else if (x == "..") {
        if (!s.empty())
          s.pop();
      } else
        s.push(x);
    }
    string ans;
    while (!s.empty()) {
      ans = "/" + s.top() + ans;
      s.pop();
    }
    return ans.length() == 0 ? "/" : ans;
  }
};