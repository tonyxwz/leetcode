// ```cpp
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
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    // vector<int> ans;
    // postorderTraversal(root, ans);
    // return ans;
    return postorderTraversalIterative(root);
  }

  void postorderTraversal(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) return;
    postorderTraversal(root->left, ans);
    postorderTraversal(root->right, ans);
    ans.push_back(root->val);
  }

  vector<int> postorderTraversalFunctional(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;

    vector<int> l = postorderTraversalFunctional(root->left);
    vector<int> r = postorderTraversalFunctional(root->right);
    ans.insert(ans.end(), l.begin(), l.end());
    ans.insert(ans.end(), r.begin(), r.end());
    ans.push_back(root->val);

    return ans;
  }

  vector<int> postorderTraversalIterative(TreeNode* root) {
    if (!root) return {};

    vector<int> ans;
    stack<TreeNode*> s;

    do {
      while (root) {
        if (root->right) s.push(root->right);
        s.push(root);
        root = root->left;
      }

      root = s.top();
      s.pop();
      if (root->right && !s.empty() && root->right == s.top()) {
        // check if root has a right child unprocessed
        // conditions:
        //      root has right child
        //      top of stack equals right child (address)
        //          top method requires that stack is not empty
        s.pop();
        s.push(root);
        root = root->right;
      } else {
        ans.push_back(root->val);
        root = nullptr;
      }
    } while (!s.empty());

    return ans;
  }

  vector<int> postorderTraversalTwoStacks(TreeNode* root) {
    if (!root) return {};
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;

    vector<int> ans;
    s1.push(root);

    while (!s1.empty()) {
      // simulation of reversed postorder (simular to preorder), instead of push
      // to ans, push to stack
      TreeNode* tmp = s1.top();
      s1.pop();
      s2.push(tmp);
      if (tmp->left) s1.push(tmp->left);
      if (tmp->right) s1.push(tmp->right);
    }
    while (!s2.empty()) {
      TreeNode* tmp = s2.top();
      s2.pop();
      ans.push_back(tmp->val);
    }
    return ans;
  }
};
// ```