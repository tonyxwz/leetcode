#include "leetcode.h"

class Solution
{
public:
  bool exist(vector<vector<char>>& board, string word)
  {

    const int m = board.size(), n = board[0].size();
    // going from direction k, board[i][j] can reach til[i][j][k]'th character
    // of word non-inclusive vector<vector<bool>> used(m, vector<bool>(n,
    // false));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        vector<vector<bool>> used(m, vector<bool>(n, false));
        if (search(i, j, board, word, used, 0))
          return true;
      }
    }
    return false;
  }

  bool search(int i,
              int j,
              const vector<vector<char>>& board,
              const string& word,
              vector<vector<bool>>& used,
              int til)
  {
    if (til == word.length())
      return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
      return false;
    if (used[i][j])
      return false;

    used[i][j] = true;
    static const int dirs[5] = { 0, -1, 0, 1, 0 };
    for (int k = 0; k < 4; ++k) {
      if (word[til] == board[i][j]) {
        if (search(i + dirs[k], j + dirs[k + 1], board, word, used, til + 1))
          return true;
      }
    }
    used[i][j] = false;
    return false;
  }
};
