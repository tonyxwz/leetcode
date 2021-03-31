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
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
  {
    unordered_map<int, int> m;
    const int n = pre.size();
    for (int i = 0; i < n; ++i)
      m[pre[i]] = i;

    function<TreeNode*(int, int, int, int)> build =
      [&](int pr1, int pr2, int po1, int po2) -> TreeNode* {
      if (pr1 > pr2 || po1 > po2)
        return nullptr;
      auto root = new TreeNode(post[po2]);
      // not equal meaing has child
      if (pr1 < pr2 && po1 < po2) {
        // no left child OR no right child -> left child
        if (post[po2 - 1] == pre[pr1 + 1]) {
          root->left = build(pr1 + 1, pr2, po1, po2 - 1);
        } else { // both children exists
          int pre_right_root = m[post[po2 - 1]];
          int n_left = pre_right_root - pr1 - 1, n_right = pr2 - pre_right_root;
          root->left =
            build(pr1 + 1, pre_right_root - 1, po1, po1 + n_left - 1);
          root->right = build(pre_right_root, pr2, po1 + n_left, po2 - 1);
        }
      }
      return root;
    };
    return build(0, n - 1, 0, n - 1);
  }
};