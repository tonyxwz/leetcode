#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
  vector<int> rightSideView(TreeNode* root)
  {
    deque<TreeNode*> q;
    vector<int> ans;
    if (root)
      q.push_back(root);

    while (!q.empty()) {
      ans.push_back(q.back()->val);
      int n = q.size();
      while (n--) {
        auto x = q.front();
        q.pop_front();
        if (x->left)
          q.push_back(x->left);
        if (x->right)
          q.push_back(x->right);
      }
    }
    return ans;
  }
};