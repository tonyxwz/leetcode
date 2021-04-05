#include "leetcode.h"

class Solution
{
public:
  void solveSudoku(vector<vector<char>>& board) { dfs(board); }

  bool valid(const vector<vector<char>>& board, int r, int c, char x)
  {
    int r_ = (r / 3) * 3;
    int c_ = (c / 3) * 3;
    for (int i = 0; i < 9; ++i) {
      if (board[r][i] == x)
        return false;
      if (board[i][c] == x)
        return false;
      if (board[r_ + (i / 3)][c_ + (i % 3)] == x)
        return false;
    }
    return true;
  }

  pair<int, int> nextPos(const vector<vector<char>>& board)
  {
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j)
        if (board[i][j] == '.')
          return { i, j };
    return { -1, -1 };
  }

  bool dfs(vector<vector<char>>& board)
  {
    auto pos = nextPos(board);
    if (pos.first < 0 && pos.second < 0)
      return true;
    for (char c = '1'; c <= '9'; ++c)
      if (valid(board, pos.first, pos.second, c)) {
        board[pos.first][pos.second] = c;
        if (dfs(board))
          return true;
        board[pos.first][pos.second] = '.';
      }
    return false;
  }
};