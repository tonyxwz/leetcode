#include "leetcode.h"

class Solution
{

public:
  vector<vector<int>> floodFill(vector<vector<int>>& image,
                                int sr,
                                int sc,
                                int newColor)
  {
    if (image[sr][sc] == newColor)
      return image;
    const int rows = image.size();
    const int cols = image[0].size();
    dfs(image, sr, sc, rows, cols, image[sr][sc], newColor);
    return image;
  }

private:
  inline static const int dirs[5] = { 0, 1, 0, -1, 0 };
  void dfs(vector<vector<int>>& image,
           int r,
           int c,
           const int rows,
           const int cols,
           const int oldColor,
           const int newColor)
  {
    if (r < 0 || r >= rows || c < 0 || c > cols)
      return;
    if (image[r][c] != oldColor)
      return;
    image[r][c] = newColor;
    for (int i = 0; i < 4; i++)
      dfs(image, r + dirs[i], c + dirs[i + 1], rows, cols, oldColor, newColor);
  }
};
