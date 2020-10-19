#include <algorithm>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

// application framework
//
// store all the trees and coordinates in a sorted list

class Solution {
    public:
        int cutOffTree(vector<vector<int>> &forest) {
            vector<tuple<int, int, int>> trees;
            r = forest.size();
            c = forest[0].size();
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    if (forest[i][j] > 1)
                        trees.emplace_back(forest[i][j], i, j);
            std::sort(trees.begin(), trees.end());

            int ans = 0;
            int sr = 0, sc = 0;
            for (const auto &t : trees) {
                int tr = std::get<1>(t);
                int tc = std::get<2>(t);
                int steps = BFS(forest, sr, sc, tr, tc);
                if (steps == -1)
                    return steps;
                forest[tr][tc] = 1;
                ans += steps;
                sr = tr;
                sc = tc;
            }
            return ans;
        }

    private:
        int r = 0;
        int c = 0;
        int BFS(vector<vector<int>> &forest,
                int r1, int c1,
                int r2, int c2) {

            queue<pair<int, int>> q;
            vector<vector<bool>> seen(r, vector<bool>(c, false));
            q.emplace(r1, c1);
            seen[r1][c1] = true;

            static vector<int> dirs{0, -1, 0, 1, 0};

            int step = 0;
            while (!q.empty()) {
                int size = q.size();
                while (size--) {
                    auto p = q.front();
                    q.pop();
                    int y = std::get<0>(p);
                    int x = std::get<1>(p);
                    if (y == r2 && x == c2)
                        return step;
                    for (int i = 0; i < 4; i++) {
                        int new_y = y + dirs[i];
                        int new_x = x + dirs[i + 1];
                        if (new_y < r && new_y >= 0 && new_x < c && new_x >= 0 &&
                                !seen[new_y][new_x] && forest[new_y][new_x]) {
                            q.emplace(new_y, new_x);
                            seen[new_y][new_x] = true;
                        }
                    }
                }
                step++;
            }
            return -1;
        }
};
