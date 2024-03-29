// https:// leetcode.com/problems/binary-tree-inorder-traversal/
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
  vector<int> inorderTraversal(TreeNode* root) {
    // vector<int> ans;
    // recursive(root, ans);
    // return ans;
    // return recursive(root);
    return iterative(root);
  }

  vector<int> recursive(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;
    vector<int> l = recursive(root->left);
    ans.insert(ans.end(), l.begin(), l.end());
    ans.push_back(root->val);
    vector<int> r = recursive(root->right);
    ans.insert(ans.end(), r.begin(), r.end());
    return ans;
  }

  void recursive(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    recursive(root->left, ans);
    ans.push_back(root->val);
    recursive(root->right, ans);
  }

  vector<int> iterative(TreeNode* root) {
    if (!root) return {};

    stack<TreeNode*> s;
    vector<int> ans;

    do {
      while (root) {
        s.push(root);
        root = root->left;
      }
      root = s.top();
      s.pop();
      ans.push_back(root->val);
      root = root->right;
    } while (!s.empty() || root != nullptr);  // Important s can be empty when
                                              // moving from root to right node
    return ans;
  }
};
// ```