# ```python
#Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if root is None: return ""
        if root.left is None and root.right is None: return str(root.val)
        l = self.serialize(root.left)
        r = self.serialize(root.right)
        return str(root.val) + "(" + l + "," + r + ")"


    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data: return None
        a = 0
        b = 0; countl = 0; countr = 0;
        for i in range(len(data)):
            if data[i] == '(': countl = countl + 1
            if data[i] == ')': countr = countr + 1
            if a==0 and data[i] == '(':
                a = i
            if countl - countr == 1 and data[i] == ',':
                b = i
                break

        if a + b == 0:
            a = len(data)
            b = len(data)
        root = TreeNode(int(data[0:a]))
        root.left = self.deserialize(data[a+1:b])
        root.right = self.deserialize(data[b+1:-1])
        return root


# Your Codec object will be instantiated and called as such:
# codec = Codec()