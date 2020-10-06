// https://leetcode.com/problems/delete-node-in-a-bst/
#include "leetcode.h"

/* Reminder:
这道题是一个很典型的多种情况讨论的题
不要怕麻烦，每一种情况都讨论一下，其实也不难

二叉树 最好的做法就是递归，思路清晰
*/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            // ==
            TreeNode* new_root = nullptr;
            if (root->left == nullptr) {
                new_root = root->right;
            } else if (root->right == nullptr) {
                new_root = root->left;
            } else {
                TreeNode* parent = root;
                new_root = parent->right;
                while(new_root->left) {
                    parent = new_root;
                    new_root = new_root->left;
                }
                // new_root should be the min of left tree
                if (parent != root) {
                    parent->left = new_root->right;
                    new_root->right = root->right;
                }
                new_root->left = root->left;
            }
            delete root;
            return new_root;
        }
    }

};
// ```