#include "leetcode.h"

class Solution
{
public:
  string countAndSay(int n)
  {
    string prev = "1";
    for (int i = 1; i < n; ++i) {
      prev = count(prev);
      // cout << prev << endl;
    }
    return prev;
  }
  string count(const string& s)
  {
    ostringstream os;
    int count = 1;
    for (int i = 0; i < s.length(); ++i) {
      if (i < s.length() - 1 && s[i + 1] == s[i])
        count++;
      else {
        // cout << s[i] << endl;
        char n = '0' + count;
        os << n << s[i];
        count = 1;
      }
    }
    return os.str();
  }
};