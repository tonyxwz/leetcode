// https://leetcode.com/problems/recover-binary-search-tree/

#include "leetcode.h"
// Reminder: inorder traversal <==> BST !!

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
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

public:
  void recoverTree(TreeNode* root) {
    inorder(root);
    swap(first->val, second->val);
  }
  void inorder(TreeNode* root) {
     if (!root) return;
     inorder(root->left);
     if(prev && prev->val > root->val) {
         if(!first) first = prev;
         second = root;
     }
     prev = root;
     inorder(root->right);
  }
};
// ```