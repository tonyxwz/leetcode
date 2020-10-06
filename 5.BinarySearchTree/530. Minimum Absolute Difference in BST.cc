// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
#include "leetcode.h"

// 二叉搜索树中序遍历的结果是按从大到小的正确顺序的

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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = nullptr;
        getMinimumDifference(root, prev, ans);
        return ans;
    }

    void getMinimumDifference(TreeNode* root, TreeNode* &prev, int &D) {
        if (!root) return;
        getMinimumDifference(root->left, prev, D);
        // in-order
        if (prev != nullptr) {
            D = min(D, abs(root->val - prev->val));
        }
        prev = root;
        getMinimumDifference(root->right, prev, D);
    }
};
// ```