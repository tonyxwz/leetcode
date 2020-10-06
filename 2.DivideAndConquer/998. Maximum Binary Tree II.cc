// https://leetcode.com/problems/maximum-binary-tree-ii/
#include "leetcode.h"

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (!root) {
            return node; 
        }
        // val should replace root;
        if (root->val < val) {
            node->left = root;
            return node;
        } else {
            root->right = insertIntoMaxTree(root->right, val);
        }
        return root; 
    }
};