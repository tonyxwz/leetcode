// https:// leetcode.com/problems/binary-tree-preorder-traversal/
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
  vector<int> preorderTraversal(TreeNode* root) {
    // vector<int> ans;
    // preorderTraversal(root, ans);
    return iterative(root);
  }

  void preorderTraversal(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) return;
    ans.push_back(root->val);
    preorderTraversal(root->left, ans);
    preorderTraversal(root->right, ans);
  }

  vector<int> iterative(TreeNode* root) {
    if (!root) return {};

    stack<TreeNode*> s;
    vector<int> ans;

    s.push(root);
    while (!s.empty()) {
      root = s.top();
      s.pop();
      ans.push_back(root->val);
      if (root->right) s.push(root->right);
      if (root->left) s.push(root->left);
    }
    return ans;
  }
};
// ```