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
class Solution
{
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); ++i)
      m[inorder[i]] = i;

    function<TreeNode*(int, int, int, int)> build =
      [&](int ps, int pe, int is, int ie) -> TreeNode* {
      if (ps > pe || is > ie)
        return nullptr;
      auto root = new TreeNode(preorder[ps]);
      int i_root = m[preorder[ps]];
      int n_left = i_root - is, n_right = ie - i_root;
      root->left = build(ps + 1, ps + n_left, is, i_root - 1);
      root->right = build(pe - n_right + 1, pe, i_root + 1, ie);
      return root;
    };
    int n = preorder.size();
    return build(0, n - 1, 0, n - 1);
  }
};
