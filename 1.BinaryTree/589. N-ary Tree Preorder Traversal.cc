// https:// leetcode.com/problems/n-ary-tree-preorder-traversal/
#include "leetcode.h"

// ```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  vector<int> preorder(Node* root) {
    // vector<int> ans;
    // recursive(root, ans);
    // return ans;
    return iterative(root);
  }

  void recursive(Node* root, vector<int>& ans) {
    if (!root) return;
    ans.push_back(root->val);
    for (auto child : root->children) {
      recursive(child, ans);
    }
  }

  vector<int> iterative(Node* root) {
    if (!root) return {};
    vector<int> ans;
    stack<Node*> s;

    s.push(root);
    while (!s.empty()) {
      root = s.top();
      s.pop();
      ans.push_back(root->val);
      for (auto c = root->children.rbegin(); c != root->children.rend(); c++) {
        s.push(*c);
      }
    }

    return ans;
  }
};
// ```