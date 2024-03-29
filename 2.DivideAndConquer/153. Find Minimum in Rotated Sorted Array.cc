// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include "leetcode.h"
// Binary search

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
    
    int findMin(vector<int>& nums, int l, int r) {
        if (nums[l] <= nums[r]) 
            // sorted or l == r
            // 这个条件不具有普遍性，在下一题中有所体现
            return nums[l];
        int m = l + (r - l) / 2;
        if (nums[m] < nums[l])
            return findMin(nums, l, m);
        // else nums[m] > nums[r]
        return findMin(nums, m+1, r);
    }
};