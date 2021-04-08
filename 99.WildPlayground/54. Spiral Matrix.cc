#include "leetcode.h"

class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix)
  {
    const int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    const int dirs[] = { 0, 1, 0, -1, 0 };
    int k = 0;
    int i = 0, j = 0;
    vector<int> ans;
    while (1) {
      ans.push_back(matrix[i][j]);
      visited[i][j] = true;
      int i_ = i + dirs[k], j_ = j + dirs[k + 1];
      if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || visited[i_][j_]) {
        k = (k + 1) % 4;
        i_ = i + dirs[k], j_ = j + dirs[k + 1];
        if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || visited[i_][j_])
          break;
      }
      i = i_, j = j_;
    }
    return ans;
  }
};