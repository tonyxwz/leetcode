#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                           vector<vector<int>>& B)
  {
    vector<vector<int>> ans;
    auto a = A.begin();
    auto b = B.begin();
    while (a != A.end() && b != B.end()) {
      const int s = max(a->front(), b->front());
      const int e = min(a->back(), b->back());
      if (s <= e)
        ans.push_back({ s, e });
      if (a->back() < b->back())
        a++;
      else
        b++;
    }
    return ans;
  }
};
