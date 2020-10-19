#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
private:
  void dfsGrow(vector<vector<int>>& A,
               int r,
               int c,
               queue<pair<int, int>>& island,
               vector<vector<bool>>& visited)
  {
    if (r >= A.size() || r < 0 ||
        c >= A[0].size() || c < 0 ||
        A[r][c] != 1 || visited[r][c])
      return;
    /* A[r][c] = 2; */
    island.emplace(r, c);
    visited[r][c] = true;
    dfsGrow(A, r + 1, c, island, visited);
    dfsGrow(A, r - 1, c, island, visited);
    dfsGrow(A, r, c + 1, island, visited);
    dfsGrow(A, r, c - 1, island, visited);
  }

public:
  int shortestBridge(vector<vector<int>>& A)
  {
    queue<pair<int, int>> q;
    bool found = false;
    vector<vector<bool>> visited(A.size(), vector<bool>(A[0].size(), false));
    for (int i = 0; i < A.size() && !found; i++) {
      for (int j = 0; j < A[0].size() && !found; j++) {
        if (A[i][j] == 1) {
          dfsGrow(A, i, j, q, visited);
          found = true;
        }
      }
    }
    int dirs[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    int step = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        const auto p = q.front();
        q.pop();
        const int r = p.first;
        const int c = p.second;

        for (int i = 0; i < 4; i++) {
          const int newr = r + dirs[i][0];
          const int newc = c + dirs[i][1];

          if (newr >= A.size() || newc >= A[0].size() ||
              newr < 0 || newc < 0 ||
              visited[newr][newc])
            continue;
          if (A[newr][newc] == 1)
            return step;
          /* A[r][c] = 1; */
          visited[newr][newc] = true;
          q.emplace(newr, newc);
        }
      }
      step++;
    }
    return -1;
  }
};
