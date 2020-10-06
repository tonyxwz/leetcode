// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
#include "leetcode.h"

// ```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size()-1);
    }

    TreeNode* toBST(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        if (l==r) return new TreeNode(nums[l]);
        int mid = l + (r-l)/2;
        TreeNode* nodel = toBST(nums, l, mid-1);
        TreeNode* noder = toBST(nums, mid+1, r);

        TreeNode* self = new TreeNode(nums[mid], nodel, noder);
        return self;
    }
};
// ```