// https:// leetcode.com/problems/symmetric-tree/
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
 * left(left), right(right) {}
 * };
 */
class Solution {
 public:
  bool isSymmetric(TreeNode* root) { return leftEqRight(root, root); }

  bool leftEqRight(TreeNode* left, TreeNode* right) {
    if (!left || !right) return !left && !right;
    if (left->val != right->val) return false;
    return leftEqRight(left->left, right->right) &&
           leftEqRight(left->right, right->left);
  }
};
// ```