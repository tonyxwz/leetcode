// ```cpp
#include "leetcode.h"
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
  vector<int> postorder(Node* root) {
    // vector<int> ans;
    // recursive(root, ans);
    // return ans;
    return iterative2(root);
  }

  void recursive(Node* root, vector<int>& ans) {
    if (!root) return;
    for (auto c : root->children) {
      recursive(c, ans);
    }
    ans.push_back(root->val);
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
      for (auto c : root->children) {
        s.push(c);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

  vector<int> iterative2(Node* root) {
    // using two stacks
    if (!root) return {};
    vector<int> ans;
    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);
    while (!s1.empty()) {
      root = s1.top();
      s1.pop();
      // do the reverse of postorder traversal first
      s2.push(root);
      for (auto c : root->children) {
        s1.push(c);
      }
    }

    while (!s2.empty()) {
      root = s2.top();
      s2.pop();
      ans.push_back(root->val);
    }
    return ans;
  }
};
// ```