// https:// leetcode.com/problems/diameter-of-binary-tree/
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
class Solution
{
public:
  int diameterOfBinaryTree(TreeNode* root)
  {
    int diameter = 0;
    perimeter(root, diameter);
    return diameter;
  }

  int perimeter(TreeNode* root, int& diameter)
  {
    if (!root)
      return -1;
    int l = perimeter(root->left, diameter) + 1;
    int r = perimeter(root->right, diameter) + 1;
    diameter = max(diameter, l + r);
    return max(l, r);
  }
};
// ```