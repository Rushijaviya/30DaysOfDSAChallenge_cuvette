# 234. Palindrome Linked List
# https://leetcode.com/problems/palindrome-linked-list/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def isPalindrome(self, head):
        slow=fast=head
        rev=None
        while fast and fast.next:
            fast=fast.next.next
            slow,rev,rev.next=slow.next,slow,rev
        if fast:
            slow=slow.next
        while slow and slow.val==rev.val:
            slow=slow.next
            rev=rev.next
        return not slow
        
        '''
        l=[]
        while head:
            l.append(head.val)
            head=head.next
        return True if l==l[::-1] else False
        '''