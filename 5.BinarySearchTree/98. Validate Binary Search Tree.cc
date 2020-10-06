// https://leetcode.com/problems/validate-binary-search-tree/
#include "leetcode.h"
// Reminder 当需要比较直到数据类型上限或者下线的数据时，可以用空指针实现。
// 如下题，避免了使用更长的数据类型long
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }

    bool isValidBST(TreeNode* root, int *lb, int *ub) {
        if (!root) return true;
        bool self = (lb == nullptr || root->val > *lb) &&
            (ub == nullptr || root->val < *ub);
        if (!root->left && !root->right) return self;
        self = self && (!root->left || root->left->val < root->val);
        self = self && (!root->right || root->right->val > root->val);
        if(!self) return false;

        bool l = isValidBST(root->left, lb, &root->val);
        bool r = isValidBST(root->right, &root->val, ub);
        return l && r && self;
    }
};
// ```