// https:// leetcode.com/problems/longest-univalue-path/
#include "leetcode.h"

// use both child tree, return only one of them.

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
  int longestUnivaluePath(TreeNode* root) {
    if (!root) return 0;
    int lp = 0;
    longestUnivaluePath(root, lp);
    return lp;
  }

 private:
  // lp: currently longest path
  // curVal: value of current univalue path
  // curN: length of current univalue path
  // return value, number of node from root downwards
  int longestUnivaluePath(TreeNode* root, int& lp) {
    if (!root) return 0;
    int l_ = longestUnivaluePath(root->left, lp);
    int r_ = longestUnivaluePath(root->right, lp);
    int l = 0;
    int r = 0;
    if (root->left && root->left->val == root->val) l = l_ + 1;
    if (root->right && root->right->val == root->val) r = r_ + 1;
    lp = max(lp, l + r);
    return max(l, r);
  }
};
// ```