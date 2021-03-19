#include "leetcode.h"

// union find
// divide each character into 4 parts.
//
// | \ 0 / |
// | 3 x 1 |
// | / 2 \ |
//
// '/' -> merge (1, 2) and (0, 3)
// '\' -> merge (0, 1) and (3, 2)

class Solution
{
public:
  int regionsBySlashes(vector<string>& grid)
  {
    const int n = grid.size();
    vector<int> parents(4 * n * n);
    iota(parents.begin(), parents.end(), 0);
    auto find = [&parents](int q) -> int {
      while (parents[q] != q) {
        parents[q] = parents[parents[q]];
        q = parents[q];
      }
      return q;
    };
    auto merge = [&](int a, int b) { parents[find(a)] = find(b); };

    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        const int index = (r * n + c) * 4;
        switch (grid[r][c]) {
          case '/':
            merge(index + 0, index + 3);
            merge(index + 1, index + 2);
            break;
          case '\\':
            merge(index + 0, index + 1);
            merge(index + 2, index + 3);
            break;
          case ' ':
            merge(index + 0, index + 1);
            merge(index + 1, index + 2);
            merge(index + 2, index + 3);
            break;
          default:
            break;
        }
        if (r + 1 < n)
          merge(index + 2, index + 4 * n);
        if (c + 1 < n)
          merge(index + 1, index + 4 + 3);
      }
    }
    int ans = 0;
    for (int i = 0, ntria = parents.size(); i < ntria; ++i)
      if (find(i) == i)
        ans++;
    return ans;
  }
};
