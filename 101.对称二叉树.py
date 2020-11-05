# -*- coding: UTF-8 -*-
#!/usr/bin/python3
# 给定一个二叉树，检查它是否是镜像对称的。

#  

# 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

#     1
#    / \
#   2   2
#  / \ / \
# 3  4 4  3

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root == None:
        	return True
        return self.check(root.left, root.right)

    def check(self, l: TreeNode, r: TreeNode) -> bool:
        if l is None and r is None:
        	return True
        if l is None or r is None:
        	return False
        return (l.val == r.val) and self.check(l.left, r.right) and self.check(l.right, r.left)


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

    print(Solution().isSymmetric(root))
