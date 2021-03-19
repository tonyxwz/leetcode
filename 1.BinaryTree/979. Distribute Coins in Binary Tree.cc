// https:// leetcode.com/problems/distribute-coins-in-binary-tree/
#include "leetcode.h"

// 因为题目保证了硬币数量和节点数量时相同的，可以用流量的角度来看这个问题。
// 如果当前的树的节点树不等于所有节点所拥有的硬币数量，那么一定会有“差值”的硬币
// 从根节点的上方路径流入或流出。以此思路写出递归函数。

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
class Solution
{
public:
  int distributeCoins(TreeNode* root)
  {
    int ans = 0;
    balance(root, ans);
    return ans;
  }

  int balance(TreeNode* root, int& ans)
  {
    if (!root)
      return 0;
    int l = balance(root->left, ans);
    int r = balance(root->right, ans);
    ans += abs(l) + abs(r);
    return l + r + root->val - 1;
  }
};
// ```