// https://leetcode.com/problems/binary-search/

#include "leetcode.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // binary search
        int a = 0;
        int b = nums.size() - 1;
        int pivot = 0; 
        while (a <= b) {
           pivot = (a + b) / 2;  
           if (nums[pivot] < target) {
               a = pivot + 1;
           } else if (nums[pivot] > target) {
               b = pivot - 1;
           } else {
               return pivot;
           }
        }
        return -1;
    }
};