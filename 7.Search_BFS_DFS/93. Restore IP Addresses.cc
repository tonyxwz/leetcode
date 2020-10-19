#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<string> restoreIpAddresses(string s)
  {
    vector<string> ans;
    dfs(s, ans, 0, "");
    return ans;
  }

private:
  void dfs(string s, vector<string>& ans, int d, string ip)
  {
    // length of the string left in s
    int l = s.length();
    if (d == 4) {
      if (l == 0)
        ans.push_back(ip);
      return;
    }
    // digits for the next ip comp
    l = min(l, 3);
    if (s[0] == '0')
      l = 1; // only iterate once if there is a leading zero
    for (int i = 1; i <= l; i++) {
      string ss = s.substr(0, i);
      if (ss.length() == 3 && stoi(ss) > 255)
        return;
      dfs(s.substr(i), ans, d + 1, ip + (d > 0 ? "." : "") + ss);
    }
  }
};

int
main()
{
  string ip = "1111111";
  Solution sol;
  auto v = sol.restoreIpAddresses(ip);
  return 0;
}
