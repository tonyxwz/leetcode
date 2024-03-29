// https:// leetcode.com/problems/path-sum/

#include "leetcode.h"
// 递归 但边界条件值得注意。当节点为空时应当返回false

//     递归到叶子节点（左右均为null）且值等于sum应该返回true

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
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right && root->val == sum) return true;

    bool l = hasPathSum(root->left, sum - root->val);
    bool r = hasPathSum(root->right, sum - root->val);
    return l || r;
  }
};
// ```