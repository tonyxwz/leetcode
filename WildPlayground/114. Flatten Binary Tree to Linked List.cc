#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
  void flatten(TreeNode* root) { dfs(root); }

  TreeNode* dfs(TreeNode* node)
  {
    if (!node)
      return nullptr;
    auto l = dfs(node->left);  // tail of left sub-tree
    auto r = dfs(node->right); // tail of right subtree
    if (l) {
      l->left = nullptr;
      if (node->right)
        l->right = node->right;
      else {
        r = l;
      }
    }
    if (node->left)
      node->right = node->left;
    node->left = nullptr;
    return r ? r : node;
  }
};
