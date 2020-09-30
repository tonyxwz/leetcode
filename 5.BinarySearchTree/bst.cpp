struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode* other = nullptr;
    inorder(root, nullptr, other);
  }

  // corrected?
  bool inorder(TreeNode* node, TreeNode* prev, TreeNode*& other) {
    if (!node) return false;
    if (!inorder(node->left, prev, other)) {
      bool corrected = false;
      if (prev != nullptr)
        if (prev->val > node->val)  // something wrong here
          if (other != nullptr) {
            int tmp = other->val;
            other->val = node->val;
            node->val = tmp;
            corrected = true;
          } else {
            other = node;
          }
      if (!corrected)
        inorder(node->right, node, other);
    }
  }
};