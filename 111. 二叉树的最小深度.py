# -*- coding: UTF-8 -*-
#!/usr/bin/python3

# 给定一个二叉树，找出其最小深度。

# 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

# 说明：叶子节点是指没有子节点的节点。

# 输入：root = [3,9,20,null,null,15,7]
# 输出：2

from queue import Queue
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def transNode(arr):
    def level(index):
        if index >= len(arr) or arr[index] is None:
            return None
        root = TreeNode(arr[index], None, None)
        root.left = level(2 * index + 1)
        root.right = level(2 * index + 2)
        return root
    return level(0)

def print_all(node):
    if node is not None:
        print(node.val)
        print_all(node.left)
        print_all(node.right)

class Solution:
    def minDepth1(self, root: TreeNode) -> int:
        if (root is None) : return 0
        q = deque([(root, 1)])
        while q:
            node, depth = q.popleft()
            if not node.left and not node.right:
                return depth
            if node.left:
                q.append((node.left, depth + 1))
            if node.right:
                q.append((node.right, depth + 1))
        return 0

    def minDepth(self, root: TreeNode) -> int:
        if (root is None) : return 0
        q = Queue()
        q.put((root, 1))
        while q:
            node, depth = q.get()
            if not node.left and not node.right:
                return depth
            if node.left:
                q.put((node.left, depth + 1))
            if node.right:
                q.put((node.right, depth + 1))

        return 0
if __name__ == '__main__':
    arr = [2,None,3,None,4,None,5,None,6]
    root = transNode(arr)
    # print_all(root)
    depth = Solution().minDepth1(root)
    print(depth)