// https:// leetcode.com/problems/path-sum-iii/
#include "leetcode.h"
// 这一题不同之处在于取消了对路径通过根节点的要求。

//     在这种情况下需要对假设每个子节点为root，累加得到的路径数量

//     但是如果题目给出了所有节点均为整数，那么可以在O(n)
//     时间内结果（使用deque）

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
  int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    // dfs
    int l = pathSum(root->left, sum);
    int r = pathSum(root->right, sum);

    int self = numPaths(root, sum);
    return self + l + r;
  }

  int numPaths(TreeNode* root, int rest) {
    // paths have to pass the root node.
    if (!root) return 0;
    int l = numPaths(root->left, rest - root->val);
    int r = numPaths(root->right, rest - root->val);

    int self;
    if (root->val == rest) {
      self = 1;
    } else {
      self = 0;
    }
    return self + l + r;
  }
};
// ```