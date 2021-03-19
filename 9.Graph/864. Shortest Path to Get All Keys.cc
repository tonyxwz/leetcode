#include "leetcode.h"
#include <cstring>

/*
"@...a"
".###A"
"b.BCc"

*/
class Solution
{
public:
  int shortestPathAllKeys(vector<string>& grid)
  {
    const int R = grid.size();
    const int C = grid[0].size();
    int r0, c0;
    int stop_mask = 0;
    for (int i = 0, nrows = grid.size(); i < nrows; ++i) {
      for (int j = 0, ncols = grid[0].size(); j < ncols; ++j) {
        if (grid[i][j] == '@') {
          r0 = i;
          c0 = j;
        }
        if (isalpha(grid[i][j]) && isupper(grid[i][j]))
          stop_mask = stop_mask | (1 << (grid[i][j] - 'A'));
      }
    }
    cout << bitset<6>(stop_mask) << endl;
    unordered_set<int> visited;
    auto hash = [R, C](int r, int c, int state) -> int {
      return (r * C + c) << 6 | state;
    };

    const int dirs[] = { 0, 1, 0, -1, 0 };
    queue<tuple<int, int, int>> q; // (row, col, keys)
    q.emplace(r0, c0, 0);
    int steps = 0;
    while (!q.empty()) {
      int qsize = q.size();
      while (qsize--) {
        auto t = q.front();
        q.pop();
        auto r = get<0>(t);
        auto c = get<1>(t);
        auto keys = get<2>(t);
        int id = hash(r, c, keys);
        if (visited.count(id))
          continue;
        visited.insert(id);

        if (islower(grid[r][c]))
          keys = keys | (1 << (grid[r][c] - 'a'));
        if (keys == stop_mask)
          return steps;
        for (int i = 0; i < 4; ++i) {
          int r_ = r + dirs[i];
          int c_ = c + dirs[i + 1];
          if (r_ < 0 || r_ >= R || c_ < 0 || c_ >= C)
            continue;
          if (grid[r_][c_] == '#')
            continue;
          if (isupper(grid[r_][c_]) && !(keys & (1 << (grid[r_][c_] - 'A'))))
            continue;
          q.emplace(r_, c_, keys);
        }
      }
      ++steps;
    }
    return -1;
  }
};