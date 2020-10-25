#include "leetcode.h"

class Solution
{
  vector<char> getAlt(char c)
  {
    vector<char> v{ c };
    if (c <= 'Z' && c >= 'A') {
      v.push_back(c + ('a' - 'A'));
    } else if (c <= 'z' && c >= 'a') {
      v.push_back(c - ('a' - 'A'));
    }
    return v;
  }
  void dfs(string S, string& curr, vector<string>& ans)
  {
    if (curr.length() == S.length()) {
      ans.push_back(curr);
      return;
    }
    vector<char> candids = getAlt(S[curr.length()]);
    for (char c : candids) {
      curr.push_back(c);
      dfs(S, curr, ans);
      curr.pop_back();
    }
  }

public:
  vector<string> letterCasePermutation(string S)
  {
    vector<string> ans;
    string curr;
    dfs(S, curr, ans);
    return ans;
  }
};

// Author: Huahua
// Running time: 7 ms
class Solution2
{
public:
  vector<string> letterCasePermutation(string S)
  {
    vector<string> ans;
    dfs(S, 0, ans);
    return ans;
  }

private:
  void dfs(string& S, int s, vector<string>& ans)
  {
    if (s == S.length()) {
      ans.push_back(S);
      return;
    }
    dfs(S, s + 1, ans);
    if (!isalpha(S[s]))
      return;
    // bitwise operation: 'A' + 32 = 'a', the fifth bit of 'A' and 'a' must be opposite.
    // Smart solution
    S[s] ^= (1 << 5);
    dfs(S, s + 1, ans);
    S[s] ^= (1 << 5);
  }
};
