// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

//Approach :-
/*
    This problem can be solved easily by making two pointers point to the heads of each of the 
    lists initally and then adding the digits one by one, while incrementing the pointers. We also
    keep track of the carry and add it accordingly at each iteration to get the result.

    Time Complexity :- O(max(M,N));
    Space Complexity :- O(1) 
*/

//Code :-
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        
        ListNode* newHead = new ListNode(0);
        ListNode* cur = newHead;
        int carry = 0;
        while(l1!=NULL || l2!=NULL){
            int x = (l1==NULL?0:l1->val);
            int y = (l2==NULL?0:l2->val);
            cur->next = new ListNode((x+y+carry)%10);
            carry = (x+y+carry)/10;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
            cur = cur->next;
            
        }
        if(carry!=0){
            cur->next = new ListNode(carry);
        }
        return newHead->next;
    }
};