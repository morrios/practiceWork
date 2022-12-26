# -*- coding: UTF-8 -*-
#!/usr/bin/python3
# from collections import deque
import collections
# 给定一个二叉树，找出其最小深度。

# 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

# 说明：叶子节点是指没有子节点的节点。

# 示例 1：
# 输入：root = [3,9,20,null,null,15,7]
# 输出：2


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        q = collections.deque([(root, 1)])
        while q is not None:
            cur, depth = q.popleft()
            if not cur.left and not cur.right:
                return depth
            if cur.left:
                q.append([cur.left, depth + 1])
            if cur.right:
                q.append([cur.right, depth + 1])
            
        return depth

     def minDepth2(self, root: TreeNode) -> int:
        if root is None:
            return 0
        if root.left is None:
            return minDepth2(root.right) + 1
        if root.right is None:
            return minDepth2(root.left) + 1
            
        return getMin(minDepth2(root.left), minDepth2(root.right))   

    def getMin(val1, val2) -> int:
        if val1 > val2:
            return val2
        return val1

if __name__ == '__main__':
    print('main')
    #[3,9,20,null,null,15,7]
    
    t = TreeNode(6)
    Solution().minDepth(t)
