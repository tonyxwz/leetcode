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
  // O(n)
  bool isBalanced(TreeNode* root) {
    // return recursive(root);
    if (!root) return true;
    bool balanced = true;
    height(root, balanced);
    return balanced;
  }

  int height(TreeNode* root, bool& balanced) {
    if (!root) return 0;
    int l = height(root->left, balanced);
    if (!balanced) return -1;
    int r = height(root->right, balanced);
    if (!balanced) return -1;

    if (abs(l - r) > 1) {
      // if current node is not balanced, set balanced to false, which will
      // terminate the following recursions. In the worst case scenario, all the
      // nodes have to be traversed (o(n))
      balanced = false;
      return -1;
    }
    return max(l, r) + 1;
  }
  // O(n logn)
  bool recursive(TreeNode* root) {
    if (!root) return true;

    bool l = isBalanced(root->left);
    bool r = isBalanced(root->right);

    int h_l = height(root->left);
    int h_r = height(root->right);

    return l && r && abs(h_l - h_r) <= 1;
  }

  int height(TreeNode* root) {
    if (!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
  }
};
// ```