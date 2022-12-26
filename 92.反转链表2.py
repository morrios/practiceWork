# -*- coding: UTF-8 -*-
#!/usr/bin/python3
# 给你单链表的头指针 head 和两个整数left 和 right ，其中left <= right 。
# 请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

# 示例
# 输入：head = [1,2,3,4,5], left = 2, right = 4
# 输出：[1,4,3,2,5]
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
    	print("solution")


if __name__ == '__main__':
	arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
	node_1 = ListNode(1)
