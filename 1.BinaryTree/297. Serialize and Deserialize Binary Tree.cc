// https:// leetcode.com/problems/serialize-and-deserialize-binary-tree/
// #Implement a codec for serializing binary trees
#include "leetcode.hpp"
// Reference : huahua

// ##解

// TODO 说明原因
// 只要按照相同的顺序编码和解码就行，在这个问题中，为了便于使用字符串流，使用了
// 前序遍历（preorder）。

// ```cpp
// Author: Huahua
// Running time: 39 ms
using namespace std;

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream out;
    serialize(root, out);
    cout << out.str() << endl;
    return out.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserialize(in);
  }

 private:
  void serialize(TreeNode* root, ostringstream& out) {
    if (!root) {
      out << "# ";
      return;
    }
    out << root->val << " ";
    serialize(root->left, out);
    serialize(root->right, out);
  }

  TreeNode* deserialize(istringstream& in) {
    string val;
    in >> val;
    cout << val << endl;
    if (val == "#") return nullptr;
    TreeNode* root = new TreeNode(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
  }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// ```

// Huahua's c++ solutions using binary bytes are awesome

// ```cpp
// Author : Huahua
// Running time: 23 ms (beat 98.07%)
class Codec2 {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream out;
    serialize(root, out);
    return out.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserialize(in);
  }

 private:
  enum STATUS { ROOT_NULL = 0x0, ROOT = 0x1, LEFT = 0x2, RIGHT = 0x4 };

  void serialize(TreeNode* root, ostringstream& out) {
    char status = 0;
    if (root) status |= ROOT;
    if (root && root->left) status |= LEFT;
    if (root && root->right) status |= RIGHT;
    out.write(&status, sizeof(char));
    if (!root) return;
    out.write(reinterpret_cast<char*>(&(root->val)), sizeof(root->val));
    if (root->left) serialize(root->left, out);
    if (root->right) serialize(root->right, out);
  }

  TreeNode* deserialize(istringstream& in) {
    char status;
    in.read(&status, sizeof(char));
    if (!status & ROOT) return nullptr;
    auto root = new TreeNode(0);
    in.read(reinterpret_cast<char*>(&root->val), sizeof(root->val));
    root->left = (status & LEFT) ? deserialize(in) : nullptr;
    root->right = (status & RIGHT) ? deserialize(in) : nullptr;
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// ```
