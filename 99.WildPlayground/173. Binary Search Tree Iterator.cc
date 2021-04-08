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
class BSTIterator
{
public:
  BSTIterator(TreeNode* root)
    : root_{ root }
    , curr_{ root }
  {}

  int next()
  {
    // if (curr_ == nullptr && st_.empty())
    //   curr_ = root_;
    while (curr_) {
      st_.push(curr_);
      curr_ = curr_->left;
    }
    curr_ = st_.top();
    st_.pop();
    int val = curr_->val;
    curr_ = curr_->right;
    return val;
  }

  bool hasNext() { return !st_.empty() || curr_; }

private:
  stack<TreeNode*> st_;
  TreeNode* root_;
  TreeNode* curr_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */