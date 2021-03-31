#include "leetcode.h"

class Solution
{
public:
  bool isValidSerialization(string preorder)
  {
    vector<string> v;
    string val;
    istringstream is(preorder);
    while (getline(is, val, ','))
      v.push_back(val);
    int i = 0;
    bool valid = decode(v, i);
    cout << i << endl;
    return valid && i == v.size();
  }

  bool decode(const vector<string>& s, int& i)
  {
    if (i >= s.size())
      return false;
    const string& val = s[i];
    i++;
    if (val == "#")
      return true;

    bool l = decode(s, i);
    bool r = decode(s, i);

    return l && r;
  }
};