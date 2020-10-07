// https://leetcode.com/problems/search-a-2d-matrix/
#include "leetcode.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int columns = rows ? matrix[0].size() : 0;
        int l = 0, r = rows * columns;
        while(l < r) {
            int m = l + (r - l) / 2;
            int row = m / columns;
            int col = m % columns;
            if (matrix[row][col] == target){
                return true;
            } else if (matrix[row][col] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return false;
    }
};
