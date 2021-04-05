#include "leetcode.h"

class Solution
{
public:
  bool isValidSudoku(vector<vector<char>>& board)
  {
    for (int i = 0; i < 9; ++i)
      if (invalid(board, i, 1, 0, 9))
        return false;

    for (int i = 0; i < 9; ++i)
      if (invalid(board, 0, 9, i, 1))
        return false;

    for (int i = 0; i < 9; i += 3)
      for (int j = 0; j < 9; j += 3)
        if (invalid(board, i, 3, j, 3))
          return false;
    return true;
  }
  bool invalid(const vector<vector<char>>& board, int r, int h, int c, int w)
  {
    vector<int> d(10, 0);
    for (int i = r; i < r + h; ++i)
      for (int j = c; j < c + w; ++j) {
        if (isdigit(board[i][j])) {
          d[board[i][j] - '0']++;
          if (d[board[i][j] - '0'] > 1)
            return true;
        }
      }
    return false;
  }
};