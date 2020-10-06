// https://leetcode.com/problems/serialize-and-deserialize-bst/
#include "leetcode.h"
// #序列化二叉树

//        题目要求尽可能节约空间

//            二叉搜索树的特点* in -
//        order* traversal得到的是正确的顺序* pre -
//        order* traversal 得到的序列特点：
//            遍历时左子树时，遇到的第一个比当前root节点大的元素的时候就是该换到右子树的时候

//                算法维护两个变量maxVal和minVal。向左移动时，更新maxVal的值为当前root的值
//                    在向右移动时，更新minVal为当前root。

// ```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  void serialize(TreeNode* root, string& s) {
    // pre-order traversal
    if (!root) return;
    // &root->val: pointer to int (32 bit / 4 byte)
    // char* pointer to char (8 bit / 1 byte)
    // reinterpret a pointer to int as array of 4 chars
    s.append(reinterpret_cast<const char*>(&root->val), sizeof(root->val));
    serialize(root->left, s);
    serialize(root->right, s);
  }

  /* @param s: string to deserialize
     @param pos: current position to reinterpret_cast
     @param minVal: min value so far
     @param maxVal: max value so far
  */
  TreeNode* deserialize(const string& s, int& offset, int minVal, int maxVal) {
    if (offset >= s.size()) return nullptr;
    // interpret the chars back to int
    // s.data() is pointer to the beginning of underlying cstring
    // plus the offset is the beginning of our integer
    // reinterpret char* as int*
    // *p is the integer
    int val = *reinterpret_cast<const int*>(s.data() + offset);
    if (val > maxVal || val < minVal)  //
      return nullptr;

    auto root = new TreeNode(val);
    offset += sizeof(int);
    // still pre-order
    root->left = deserialize(s, offset, minVal, val);
    root->right = deserialize(s, offset, val, maxVal);
    return root;
  }

 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string s;
    serialize(root, s);
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    int offset = 0;
    auto root = deserialize(data, offset, INT_MIN, INT_MAX);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// ```