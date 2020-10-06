// ```cpp
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
class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    int min_depth = INT_MAX;
    depth(root, 1, min_depth);
    return min_depth;
  }

  int depth(TreeNode* root, int d, int& min_depth) {
    if (!root) return 0;
    if (isLeaf(root)) min_depth = min(min_depth, d);
    int l = depth(root->left, d + 1, min_depth);
    int r = depth(root->right, d + 1, min_depth);
    return min(l, r) + 1;
  }

  bool isLeaf(TreeNode* node) { return !node->left && !node->right; }
};
// ```