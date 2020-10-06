// https:// leetcode.com/problems/binary-tree-maximum-path-sum/
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
  int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    oneSideMax(root, ans);
    return ans;
  }

  int oneSideMax(TreeNode* root, int& ans) {
    if (!root) return 0;
    int l = max(0, oneSideMax(root->left, ans));
    int r = max(0, oneSideMax(root->right, ans));
    int s = l + r + root->val;
    ans = max(s, ans);
    // should return one-sided maximum sum
    return max(l, r) + root->val;
  }
};
// ```