// https:// leetcode.com/problems/same-tree/
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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if ((p == nullptr) || (q == nullptr))
      return (p == nullptr) && (q == nullptr);

    bool l = isSameTree(p->left, q->left);
    bool r = isSameTree(p->right, q->right);
    return (p->val == q->val) && l && r;
  }
};
// ```