// https:// leetcode.com/problems/trim-a-binary-search-tree/
#include "leetcode.h"
// #递归算法：

// 如果root的值比L小那么要找到子树一定再root的右子树里面，
// 相同地，如果root的值比R还要大，那么要找的子树一定再root的左子树里面。
// 最后一种情况root值恰好在L和R之间，那么可以以当前root为返回的子树根节点，
// 并递归处理左子树和右子树。

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
  TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (!root) return root;
    if (root->val > R) return trimBST(root->left, L, R);
    if (root->val < L) return trimBST(root->right, L, R);

    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
  }
};
// ```