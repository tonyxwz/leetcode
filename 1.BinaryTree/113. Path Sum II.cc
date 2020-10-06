// https:// leetcode.com/problems/path-sum-ii/
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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> current_path;
    pathSum(root, sum, current_path, ans);
    return ans;
  }

  void pathSum(TreeNode* root, int sum, vector<int>& current_path,
               vector<vector<int>>& ans) {
    if (!root) return;
    current_path.push_back(root->val);
    if (!root->left && !root->right && root->val == sum) {
      // vector::push_back copy (or move) the new elements. so further
      // operation on current_path won't affect those paths already pushed to
      // ans
      ans.push_back(current_path);
    }
    pathSum(root->left, sum - root->val, current_path, ans);
    pathSum(root->right, sum - root->val, current_path, ans);
    current_path.pop_back();
  }
};
// ```
