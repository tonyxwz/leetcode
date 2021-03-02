#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Note: nested dfs

class Solution
{

public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
  {
    this->target = target;
    this->K = K;
    dfs(root);
    return ans;
  }

private:
  TreeNode* target;
  vector<int> ans;
  int K;
  int dfs(TreeNode* node)
  {
    if (!node)
      return -1;
    if (node == target) {
      add_subtree(node, K);
      return 0;
    }
    int l = dfs(node->left);
    int r = dfs(node->right);
    if (l >= 0) {
      // if target appears in the left subtree, and the distance from target to
      // left child is `l`. Then the distance to root is `l + 1`, the distance
      // to right child is `d + 2`. Add right subtree with node at the distance
      // of `K - (d + 2)`.
      if (l == K - 1)
        ans.push_back(node->val);
      add_subtree(node->right, K - l - 2);
      return l + 1;
    }
    if (r >= 0) {
      if (r == K - 1)
        ans.push_back(node->val);
      add_subtree(node->left, K - r - 2);
      return r + 1;
    }
    return -1;
  }
  // root: starting node, d: distance to target
  void add_subtree(TreeNode* root, int d)
  {
    if (!root || d < 0)
      return;
    if (d == 0)
      ans.push_back(root->val);
    add_subtree(root->left, d - 1);
    add_subtree(root->right, d - 1);
  }
};
