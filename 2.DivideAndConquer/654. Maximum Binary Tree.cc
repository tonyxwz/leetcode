// https://leetcode.com/problems/maximum-binary-tree/
#include "leetcode.h"

// 需要熟练运用C++ containers和iterator
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return makeBMT(nums, 0, nums.size() );
    }
    
    TreeNode* makeBMT(vector<int>& nums, int l, int r) {
        if (l >= r) return nullptr;
        vector<int>::iterator it = std::max_element(nums.begin()+l, nums.begin() + r);
        int m = it - nums.begin();
        TreeNode* root = new TreeNode(*it);
        root->left = makeBMT(nums, l, m);
        root->right = makeBMT(nums, m+1, r);
        return root;
    }
};