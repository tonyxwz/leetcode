// https:// leetcode.com/problems/delete-leaves-with-a-given-value/
#include "leetcode.h"

// 思路：后序遍历树如果左孩子和右孩子都是空且root
//     ->val等于target，那么删除当前节点。删除的方式是返回空值即可。

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
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    // dfs
    if (!root) return root;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if (!root->left && !root->right && root->val == target) {
      return nullptr;
    }
    return root;
  }
};
// ```