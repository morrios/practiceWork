#
# @lc app=leetcode.cn id=21 lang=python3
#
# [21] 合并两个有序链表
#

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # @lc code=end
        if not list1: return list2;
        if not list2: return list1;
        if not list1 and not list2: return None;
        p = ListNode(-1, None);
        dumy = p;
        while(list1.next and  list2.next):
            if list1.val < list2.val:
                dumy.next = list1;
                list1 = list1.next;
            else:
                dumy.next = list2;
                list2 = list2.next;
            dumy = dumy.next;
        if (list1.next):
            dumy.next = list1;
        if(list2.next):
            dumy.next = list2;
            
        return p.next;
# @lc code=end

