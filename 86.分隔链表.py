#
# @lc app=leetcode.cn id=86 lang=python3
#
# [86] 分隔链表
#
from typing import Optional

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        p = head;
        p1 = ListNode(-1);
        p2 = ListNode(-1);
        p1_head = p1;
        p2_head = p2;
        while(p):
            if(p.val < x):
                p1.next = p;
                p1 = p1.next;
            else:
                p2.next = p;
                p2 = p2.next;
            dump = p;
            p = p.next;
            dump.next = None;
        p1.next = p2_head.next;
        return p1_head.next;
   

# @lc code=end

def generate_node(nums):
    # 定义一个哑节点
    p_head = ListNode(-1);
    p = p_head;
    for v in nums:
        temp = ListNode(v);
        p.next = temp;
        p = p.next;
    return p_head.next;

def printList(head: ListNode):
    p = head;
    while(p != None):
        print(p.val)
        p = p.next;
list = generate_node([1,4,3,2,5,2]);
solution = Solution();
reslut = solution.partition(list, 3);
# printList(reslut);