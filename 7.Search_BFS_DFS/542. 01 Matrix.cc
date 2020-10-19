#include "leetcode.h"

class Solution
{
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
  {
    const int m = matrix.size();
    const int n = matrix[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> seen(m, vector<int>(n, 0));
    vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          q.push({ i, j });
          seen[i][j] = 1;
        }
      }
    }

    vector<int> dires{ 0, 1, 0, -1, 0 };
    int step = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto coord = q.front();
        q.pop();
        int i = coord.first;
        int j = coord.second;

        ans[i][j] = step;
        for (int k = 0; k < 4; k++) {
          int y = i + dires[k];
          int x = j + dires[k + 1];
          if (y >= m || y < 0 || x >= n || x < 0 || seen[y][x])
            continue;
          q.push({ y, x });
          seen[y][x] = 1;
        }
      }
      step++;
    }
    return ans;
  }
};

// DP
// DP three question:
// - where am i?
// - how can i calculate the value for the current position
//   based on the values already calculated
// - when should i stop?
class Solution2
{
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
  {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> ans(m, vector<int>(n, m + n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0)
          ans[i][j] = 0;
        else {
          if (i > 0)
            ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
          if (j > 0)
            ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
        }
      }
    }

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (matrix[i][j]) {
          if (i < m - 1)
            ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
          if (j < n - 1)
            ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
        }
      }
    }
    return ans;
  }
};
