# 141. Linked List Cycle
# https://leetcode.com/problems/linked-list-cycle/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head):
        while head:
            if head.val==100001:
                return True
            head.val=100001
            head=head.next
        return False