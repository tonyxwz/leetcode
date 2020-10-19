#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
  bool isPalindrome(string& s, int l, int r)
  {
    bool ans = true;
    while (l < r) {
      ans = ans && (s[l] == s[r]);
      l++;
      r--;
    }
    return ans;
  }

  void dfs(string& s, int l, vector<string>& v, vector<vector<string>>& ans)
  {
    if (l == s.length()) {
      ans.push_back(v);
      return;
    }
    for (int i = l; i < s.length(); i++) {
      if (!isPalindrome(s, l, i))
        continue;
      v.push_back(s.substr(l, i - l + 1));
      dfs(s, i + 1, v, ans);
      v.pop_back();
    }
  }

public:
  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> ans;
    vector<string> curr;
    dfs(s, 0, curr, ans);
    return ans;
  }
};
