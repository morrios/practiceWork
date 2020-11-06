# -*- coding: UTF-8 -*-
#!/usr/bin/python3
# from collections import deque
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0

        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
        
if __name__ == "__main__":
    root = TreeNode(1)
    node2_l = TreeNode(2)
    node2_r = TreeNode(2)

    node3_1 = TreeNode(3)
    node3_2 = TreeNode(4)
    node3_3 = TreeNode(4)
    node3_4 = TreeNode(3)

    root.left = node2_l
    root.right = node2_r

    node2_l.left = node3_1
    node2_l.right = node3_2

    node2_r.left = node3_3
    node2_r.right = node3_4
    print(Solution().maxDepth(root))