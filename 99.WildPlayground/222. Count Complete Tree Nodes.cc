#include "leetcode.h"

// complete binary tree

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
  int countNodes(TreeNode* root)
  {
    if (!root)
      return 0;
    int hl = 0, hr = 0;
    auto left = root, right = root;
    while (left) {
      left = left->left;
      hl++;
    }
    while (right) {
      right = right->right;
      hr++;
    }

    if (hl == hr)
      return pow(2, hl) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};