// https:// leetcode.com/problems/maximum-depth-of-binary-tree/

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
  int maxDepth(TreeNode* root) { return bfs(root); }

  int recursive(TreeNode* root) {
    if (!root) return 0;
    // maxdepth = max(leftmax, rightmax) + 1
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l, r) + 1;
  }

  int bfs(TreeNode* root) {
    if (!root) return 0;
    int depth = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int n_level = q.size();
      depth++;
      while (n_level--) {
        root = q.front();
        q.pop();
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
    }
    return depth;
  }

  int iterative(TreeNode* root) {
    if (!root) return 0;
    int max_depth = 0;

    stack<pair<TreeNode*, int>> s;
    s.push({root, 1});
    while (!s.empty()) {
      auto p = s.top();
      s.pop();
      max_depth = max(p.second, max_depth);
      if (p.first->right) s.push({p.first->right, p.second + 1});
      if (p.first->left) s.push({p.first->left, p.second + 1});
    }
    return max_depth;
  }
};
// ```