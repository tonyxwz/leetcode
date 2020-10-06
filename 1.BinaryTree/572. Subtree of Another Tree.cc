// https:// leetcode.com/problems/subtree-of-another-tree/
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
  bool isSubtree(TreeNode* s, TreeNode* t) {
    stack<TreeNode*> st;
    st.push(s);
    while (!st.empty()) {
      s = st.top();
      st.pop();
      if (isSameTree(s, t)) {
        return true;
      }
      if (s->left) st.push(s->left);
      if (s->right) st.push(s->right);
    }
    return false;
  }

  bool isSameTree(TreeNode* a, TreeNode* b) {
    if (!a || !b) return !a && !b;
    bool l = isSameTree(a->left, b->left);
    bool r = isSameTree(a->right, b->right);
    return l && r && a->val == b->val;
  }
};
// ```