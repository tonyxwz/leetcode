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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); ++i)
      m[inorder[i]] = i;
    return build(
      inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, m);
  }

  TreeNode* build(const vector<int>& inorder,
                  int is,
                  int ie,
                  const vector<int>& postorder,
                  int ps,
                  int pe,
                  unordered_map<int, int>& m)
  {
    if (is > ie || ps > pe)
      return nullptr;
    auto root = new TreeNode(postorder[pe]);
    int i_root = m[postorder[pe]];
    int n_left = i_root - is, n_right = ie - i_root;
    root->left =
      build(inorder, is, i_root - 1, postorder, ps, ps + n_left - 1, m);
    root->right =
      build(inorder, i_root + 1, ie, postorder, ps + n_left, pe - 1, m);
    return root;
  }
};