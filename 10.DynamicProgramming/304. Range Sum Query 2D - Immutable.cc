#include "leetcode.h"

// Attention: member initialization list should follow the same order as the
// members are declared
class NumMatrix
{
public:
  NumMatrix(vector<vector<int>>& matrix)
    : M{ matrix }
    , rows{ M.size() }
    , cols{ M[0].size() }
    , dp(vector<int>(rows * cols, 0))
    , curr_{ -1 }
  {}

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return sumRegion(row2, col2) - sumRegion(row1 - 1, col2) -
           sumRegion(row2, col1 - 1) + sumRegion(row1 - 1, col1 - 1);
  }

private:
  const vector<vector<int>>& M;
  size_t rows;
  size_t cols;
  vector<int> dp;
  int curr_;

  int sumRegion(int r, int c)
  {
    if (r < 0 || c < 0)
      return 0;
    const int curr = r * cols + c; // 0 index

    if (curr > curr_) {
      for (int i = curr_ + 1; i <= curr; ++i) {
        int row = i / cols;
        int col = i % cols;
        dp[i] = M[row][col];

        if (row > 0)
          dp[i] += dp[i - cols];

        if (col > 0)
          dp[i] += dp[i - 1];

        if (row > 0 && col > 0)
          dp[i] -= dp[(row - 1) * cols + col - 1];
      }
      curr_ = curr;
    }

    return dp[curr];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
