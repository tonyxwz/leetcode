#include <vector>
using namespace std;

class Solution
{
public:
  int numIslands(vector<vector<char>>& grid)
  {
    const int rows = grid.size();
    const int cols = grid[0].size();
    int ans = 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          ++ans;
          dfs(i, j, grid, visited);
        }
      }
    }
    return ans;
  }

private:
  void dfs(int r,
           int c,
           vector<vector<char>>& grid,
           vector<vector<bool>>& visited)
  {
    if (r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 ||
        visited[r][c] || grid[r][c] == '0')
      return;
    visited[r][c] = true;
    dfs(r-1, c, grid, visited);
    dfs(r+1, c, grid, visited);
    dfs(r, c-1, grid, visited);
    dfs(r, c+1, grid, visited);
  }
};
