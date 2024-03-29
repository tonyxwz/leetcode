// https:// leetcode.com/problems/most-frequent-subtree-sum/
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
  vector<int> findFrequentTreeSum(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;
    unordered_map<int, int> m;
    int max_time = 0;
    sumOfTree(root, m, max_time, ans);
    return ans;
  }

  int sumOfTree(TreeNode* root, unordered_map<int, int>& m, int& max_time,
                vector<int>& ans) {
    if (!root) return 0;
    int sum = root->val + sumOfTree(root->left, m, max_time, ans) +
              sumOfTree(root->right, m, max_time, ans);
    int freq = ++m[sum];
    if (freq > max_time) {
      max_time = freq;
      ans.clear();
    }
    if (max_time == freq) ans.push_back(sum);
    return sum;
  }
};
// ```