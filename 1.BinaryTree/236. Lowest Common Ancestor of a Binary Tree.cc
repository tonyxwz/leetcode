// https:// leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
#include "leetcode.h"
/* Given the assumptions that `p` and `q` are present in the
    tree and `p` and `q` are unique

  This work fine if only one query is required. However, if it is required to
  query LCA very often of a tree (unchanged), Eulerian path method is a better
  approach.
  video: https://www.youtube.com/watch?v=sD1IoalFomA
*/

// ```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // given the condition that q and p are always present and unique
    // there's no need to consider the situation when p is ancestor of q
    // because if this is the case, then return p is still valid.
    if (!root || root == p || root == q) return root;
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if (l && r) return root;
    return l ? l : r;
  }
};
// ```