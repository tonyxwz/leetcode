#include "leetcode.h"

// Note Search from top right corner
class Solution
{
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target)
  {
    const int rows = matrix.size(), cols = matrix[0].size();
    int r = 0, c = cols - 1;
    while (r < rows && c >= 0) {
      // cout << r << " " << c << endl;
      if (matrix[r][c] == target)
        return true;
      if (matrix[r][c] > target) {
        c--;
      } else {
        r++;
      }
    }
    return false;
  }
};