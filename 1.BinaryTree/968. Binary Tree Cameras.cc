// https :  // leetcode.com/problems/binary-tree-cameras/
#include "leetcode.h"

/* 找到最少数量的摄像头能够观察所有节点

1. **贪婪法**
能用贪婪法解决的问题，贪婪法往往是最优解。
 贪婪动机：If a node has its children covered and has a parent,
 then it is strictly better to place the camera at this node's parent.

2. **动态规划**

假定子树符合要求被全部覆盖，问当前节点的状态。一共有三种状态
  1.子节点被自己的子节点覆盖但是当前节点未被覆盖。
  2.当前节点被子节点（们）覆盖，但自己没有放照相机
  3.当前节点安装了相机

从这三种状态中可以推导下一个状态
  1. 两个子节点全部在状态2
  2. 子节点中至少有一个是状态3，否则是状态2
  3. 无所谓子节点的状态

使每一个节点的三种状态的最小代价以数组的形式返回
`[dp0, dp1, dp2]` 那么有两个子节点的状态码
```python
left = [ a, b, c ] right = [ d, e, f ]
```
当前节点的状态码应该是
```python
current = [
  #两个状态2的子节点
  left[1] + right[1],
  #两个子树或者是2，或者是3，且保证至少有一个是状态3
  min(left[2] + min(right[1], right[2]),
  min(left[1], left[2]) + right[2]),
  #放置相机在当前的节点
  1 + min(left) + min(right)
]
*/

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

enum struct State { CAMERA, COVERED, NONE };
class Solution {
 public:
  int minCameraCover(TreeNode* root) {
    this->_ans = 0;
    if (State::NONE == findCameras(root)) this->_ans++;
    return this->_ans;
  }

 private:
  int _ans = 0;
  // huahua: greedy and recursive
  State findCameras(TreeNode* root) {
    if (!root) return State::COVERED;
    State l = findCameras(root->left);
    State r = findCameras(root->right);
    if (l == State::NONE || r == State::NONE) {
      this->_ans++;
      return State::CAMERA;
    }
    if (l == State::CAMERA || r == State::CAMERA) {
      return State::COVERED;
    }
    return State::NONE;
  }
};
// ```