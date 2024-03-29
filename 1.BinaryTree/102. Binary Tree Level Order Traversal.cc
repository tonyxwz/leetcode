// https:// leetcode.com/problems/binary-tree-level-order-traversal/

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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};

    vector<vector<int>> ans;
    vector<TreeNode*> curr, next;
    curr.push_back(root);

    while (!curr.empty()) {
      ans.push_back({});
      for (auto n : curr) {
        ans.back().push_back(n->val);
        if (n->left) next.push_back(n->left);
        if (n->right) next.push_back(n->right);
      }
      curr.swap(next);
      next.clear();
    }
    return ans;
  }
};
// ```