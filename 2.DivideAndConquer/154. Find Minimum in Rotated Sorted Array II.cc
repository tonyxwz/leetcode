// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
#include "leetcode.h"
// 与之前不同的地方在于，本题允许元素重复，当左右位置相等的时候，不能简单的判定内部排序的情况。
// 代码虽然相同但是时间复杂度不同。

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
    
    int findMin(vector<int>& nums, int l, int r) {
        if (l + 1 >= r)
            return min(nums[l], nums[r]);
        if (nums[l] < nums[r])
            return nums[l];
        int m = l + (r - l) / 2; 
        return min(
            findMin(nums, l, m),
            findMin(nums, m+1, r)
        );
    }
};