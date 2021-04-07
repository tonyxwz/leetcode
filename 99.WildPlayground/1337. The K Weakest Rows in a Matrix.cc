#include "leetcode.h"

class Solution
{
public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
  {
    vector<int> idx(mat.size());
    iota(idx.begin(), idx.end(), 0);
    auto cmp = [&mat](const int a, const int b) -> bool {
      int nsol_a =
        upper_bound(mat[a].begin(), mat[a].end(), 1, greater<int>()) -
        mat[a].begin();
      int nsol_b =
        upper_bound(mat[b].begin(), mat[b].end(), 1, greater<int>()) -
        mat[b].begin();
      // cout << nsol_a << " " << nsol_b << endl;
      if (nsol_a < nsol_b)
        return true;
      else if (nsol_a > nsol_b)
        return false;
      else
        return a < b;
    };

    sort(idx.begin(), idx.end(), cmp);

    return vector<int>(idx.begin(), idx.begin() + k);
  }
};