// https:// leetcode.com/problems/leaf-similar-trees/
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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    if (!root1 || !root2) return !root1 && !root2;
    vector<int> leaves1;
    findLeaves(root1, leaves1);
    vector<int> leaves2;
    findLeaves(root2, leaves2);
    return leaves1 == leaves2;
  }

  void findLeaves(TreeNode* root, vector<int>& leaves) {
    if (!root->left && !root->right) leaves.push_back(root->val);
    if (root->left) findLeaves(root->left, leaves);
    if (root->right) findLeaves(root->right, leaves);
  }
};
// ```