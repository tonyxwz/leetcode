// https:// leetcode.com/problems/deepest-leaves-sum/

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
  int deepestLeavesSum(TreeNode* root) {
    if (!root) return 0;
    vector<int> zleaves;
    int max_depth = 0;
    dfs(root, zleaves, 0, max_depth);
    return accumulate(zleaves.begin(), zleaves.end(), 0);
  }

  void dfs(TreeNode* root, vector<int>& zleaves, int depth, int& max_depth) {
    if (!root) return;
    if (depth > max_depth) {
      zleaves.erase(zleaves.begin(), zleaves.end());
      max_depth = depth;
      zleaves.push_back(root->val);
    } else if (depth == max_depth) {
      zleaves.push_back(root->val);
    }
    dfs(root->left, zleaves, depth + 1, max_depth);
    dfs(root->right, zleaves, depth + 1, max_depth);
  }
};
// ```