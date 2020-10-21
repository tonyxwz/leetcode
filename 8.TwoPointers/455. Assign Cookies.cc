#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution
{
public:
  int findContentChildren(vector<int>& g, vector<int>& s)
  {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int n = 0;
    int child = 0;
    int cookie = 0;
    while (child < g.size() && cookie < s.size()) {
      if (g[child] <= s[cookie]) {
        n++;
        child++;
        cookie++;
      } else {
        cookie++;
      }
    }
    return n;
  }
};
