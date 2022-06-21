//876. Middle of the Linked List
//Problem Link :- https://leetcode.com/problems/middle-of-the-linked-list/

//Naive Approach 
/*
    The simplest approach is to first find the length of the linked by traversing the list.
    Then we can start again from the head of the list and traverse uptil (length/2) nodes to 
    find the middle node of the linked list.
    Time Complexity :- O(N)
    Space Complexity :- O(1) 

    Code :- 
    class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            if(head==NULL || head->next==NULL){
                return head;
            }
            
            int n = 0;
            ListNode* temp = head;
            while(temp!=NULL){
                ++n;
                temp = temp->next;
            }
            
            int count = 0;
            temp = head;
            while(count<n/2){
                temp = temp->next;
                ++count;
            }
            
            return temp;
        }
    };
*/

//Efficient Approach :-
/*
    Instead of traversing the list twice as in the naive approach, we can also solve the problem 
    in one pass. The idea is to have two pointers, both pointing initially to the head of the list. 
    Then we move one pointer twice as fast as the other one until it becomes null. By the time the 
    fast pointer reaches the end of the list, the slow pointer will point to the middle of the list.
    Time Complexity :- O(N)
    Space Complexity :- O(N)
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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
};