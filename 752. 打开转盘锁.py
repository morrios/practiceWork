# -*- coding: UTF-8 -*-
#!/usr/bin/python3

# 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

# 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

# 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

# 字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

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
    def plusOne(self, s: str, index: int) -> str:
        arr = list(map(int, list(s)))
        if index < len(arr):
            if arr[index] == 9:
                arr[index] = 0
            else:
                arr[index] = arr[index] + 1
        return ''.join(list(map(str, arr)))
    def minuOne(self, s: str, index: int) -> str:
        arr = list(map(int, list(s)))
        if index < len(arr):
            if arr[index] == 0:
                arr[index] = 9
            else:
                arr[index] = arr[index] - 1
        return ''.join(list(map(str, arr)))
    def openLock(self, deadends: list[str], target: str) -> int:
        root = '0000'
        for i in (-1, 1):
            print(i)
        return -1
        
    def openLock_first(self, deadends: list[str], target: str) -> int:
        root = '0000'
        deads = set(deadends)
        q = deque([root])
        visited = set(root)
        step = 0
        while q:
            for i in range(len(q)):
                cur = q.popleft()
                if cur in deads:
                    continue
                if cur == target:
                    return step
                for j in range(4):
                    up = self.plusOne(cur, j)
                    if up not in visited:
                        q.append(up)
                        visited.add(up)
                    down = self.minuOne(cur, j)
                    if down not in visited:
                        q.append(down)
                        visited.add(down)
            step += 1

        return -1
if __name__ == '__main__':
    a = Solution().openLock(['2939','0100'], '0110')
    print(a)
    