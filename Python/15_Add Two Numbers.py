# 2. Add Two Numbers
# https://leetcode.com/problems/add-two-numbers/

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1, l2):
        '''
        x=""
        curr=l1
        while curr:
            x+=str(curr.val)
            curr=curr.next
        y=""
        curr=l2
        while curr:
            y+=str(curr.val)
            curr=curr.next
        s=int(x[::-1])+int(y[::-1])
        l=[int(i) for i in str(s)]
        head=ListNode(l.pop())
        curr=head
        while l:
            curr.next=ListNode(l.pop())
            curr=curr.next
        return head
        '''

        head=ListNode()
        curr=head
        carry=0
        while l1 or l2 or carry:
            sum=0
            if l1:
                sum+=l1.val
                l1=l1.next
            if l2:
                sum+=l2.val
                l2=l2.next
            if carry:
                sum+=carry
            val=sum%10
            carry=sum//10
            curr.next=ListNode(val)
            curr=curr.next
        return head.next