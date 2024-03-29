// https:// leetcode.com/problems/univalued-binary-tree/
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
  bool isUnivalTree(TreeNode* root) {
    if (!root) return true;

    bool l = isUnivalTree(root->left);
    bool r = isUnivalTree(root->right);
    bool ans = true;
    if (root->left) ans = ans && root->val == root->left->val;
    if (root->right) ans = ans && root->val == root->right->val;
    return ans && l && r;
  }
};
// ```