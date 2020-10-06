// https:// leetcode.com/problems/house-robber-iii/
#include "leetcode.h"
//  动态规划，总是返回选择当前方案的最大期望值 本题中定义了一个结构体Exp
//      .yes和no成员表示选中这个节点和不选这个节点得到的金额最大值。当一个节点被选中时，得到的金额最大值是当前节点加不选两个子节点。当一个节点没有被选中时，左右子树随意选择，max(
//          l.yes, l.no) +
// max(r.yes, r.no)
// .
//
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

struct Exp {
  int yes;
  int no;
};

class Solution {
 public:
  int rob(TreeNode* root) {
    Exp e = plan(root);
    return max(e.yes, e.no);
  }

  Exp plan(TreeNode* root) {
    if (!root) return {0, 0};
    auto l = plan(root->left);
    auto r = plan(root->right);
    int yes = root->val + l.no + r.no;
    int no = max(l.yes, l.no) + max(r.yes, r.no);
    return {yes, no};
  }
};
// ```