// https:// leetcode.com/problems/sum-root-to-leaf-numbers/
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
  int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    int ans = 0;
    traversal(root, 0, ans);
    return ans;
  }

  void traversal(TreeNode* root, int num, int& ans) {
    if (!root) return;
    num = num * 10 + root->val;
    if (!root->left && !root->right) ans += num;
    traversal(root->left, num, ans);
    traversal(root->right, num, ans);
  }
};
// ```