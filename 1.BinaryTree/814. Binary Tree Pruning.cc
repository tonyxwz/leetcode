// https:// leetcode.com/problems/binary-tree-pruning/
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
  TreeNode* pruneTree(TreeNode* root) {
    if (!root) return root;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->val == 1 || root->left || root->right) return root;
    // delete root;
    return nullptr;
  }

  TreeNode* pruneTree2(TreeNode* root) {
    if (!has1(root)) return nullptr;
    return root;
  }

  bool has1(TreeNode* root) {
    if (!root) return false;
    bool l = has1(root->left);
    bool r = has1(root->right);
    if (!l) root->left = nullptr;
    if (!r) root->right = nullptr;
    return l || r || root->val == 1;
  }
};
// ```