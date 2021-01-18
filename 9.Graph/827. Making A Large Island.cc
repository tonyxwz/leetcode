#include "leetcode.h"

class Solution
{
public:
  int largestIsland(vector<vector<int>>& grid)
  {
    rows = grid.size();
    cols = grid[0].size();
    int color = 1;
    int ans = 0;
    // vector<vector<int>> groups(rows, vector<int>(cols, 0));

    // calculate the area of different colors (islands)
    unordered_map<int, int> areas;
    areas[0] = 0;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 1) {
          color++;
          areas[color] = getArea(grid, i, j, color);
          ans = max(ans, areas[color]);
        }
      }
    }

    // check all the zeros
    const int dirs[] = { 0, 1, 0, -1, 0 };
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < rows; ++j) {
        if (grid[i][j] == 0) {
          int area = 1;
          for (int c : set<int>{ getColor(grid, i - 1, j),
                                 getColor(grid, i + 1, j),
                                 getColor(grid, i, j + 1),
                                 getColor(grid, i, j - 1) }) {
            area += areas[c];
          }
          ans = max(ans, area);
        }
      }
    }
    return ans;
  }

private:
  int rows;
  int cols;

  int getColor(vector<vector<int>>& grid, int y, int x)
  {
    if (y < 0 || y >= rows || x < 0 || x >= cols)
      return 0;
    return grid[y][x];
  }

  int getArea(vector<vector<int>>& grid, int y, int x, int newColor)
  {
    if (y < 0 || y >= rows || x < 0 || x >= cols)
      return 0;
    if (grid[y][x] != 1) // doesn't matter
      return 0;
    grid[y][x] = newColor;
    return 1 + getArea(grid, y - 1, x, newColor) +
           getArea(grid, y + 1, x, newColor) +
           getArea(grid, y, x - 1, newColor) +
           getArea(grid, y, x + 1, newColor);
  }
};

class DisjointSet2d
{
public:
  DisjointSet2d(int rows, int cols)
    : rows(rows)
    , cols(cols)
    , parents(vector<int>(rows * cols, 0))
    , ranks(vector<int>(rows * cols, 0))
  {
    for (int i = 0; i < rows * cols; ++i)
      parents[i] = i;
  }

  int find(int r, int c) { return find(at(r, c)); }
  int find(int id)
  {
    if (parents[id] != id)
      parents[id] = find(parents[id]);
    return parents[id];
  }

  bool union_(int r1, int c1, int r2, int c2)
  {
    return union_(at(r1, c1), at(r2, c2));
  }

  bool union_(int u, int v)
  {
    const int pu = find(u);
    const int pv = find(v);

    if (pu == pv)
      return false;
    if (ranks[pu] < ranks[pv])
      parents[pu] = pv;
    else if (ranks[pu] > ranks[pv])
      parents[pv] = pu;
    else {
      parents[pu] = pv;
      ranks[pv]++;
    }
    return true;
  }

private:
  int rows;
  int cols;
  inline int at(int r, int c) { return r * cols + c; }
  vector<int> parents;
  vector<int> ranks;
};

class Solution2 // do not touch grid
{
public:
  int largestIsland(const vector<vector<int>>& grid) {
  }
private:
};
