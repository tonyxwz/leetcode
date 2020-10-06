
# current = [
#   # 两个状态2的子节点
#   left[1] + right[1],
#   # 两个子树或者是2，或者是3，且保证至少有一个是状态3
#   min(left[2] + min(right[1], right[2]), min(left[1], left[2]) + right[2]),
#   # 放置相机在当前的节点
#   1 + min(left) + min(right)
# ]

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def minCameraCover(self, root: TreeNode) -> int:
      def solve(node):
          if node is None:
              # why 1000???
              return 0, 0, 1000
          l = solve(node.left)
          r = solve(node.right)

          dp0 = l[1] + r[1]
          dp1 = min(l[2] + min(r[1:]), min(l[1:]) + r[2])
          dp2 = 1 + min(l) + min(r)

          return dp0, dp1, dp2
      return min(solve(root)[1:])