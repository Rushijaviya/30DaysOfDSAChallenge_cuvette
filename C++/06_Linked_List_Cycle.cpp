//141. Linked List Cycle
//Problem Link :- https://leetcode.com/problems/linked-list-cycle/

//Naive Approach :-
/*
    The brute force approach is to start from the head of the linked list, and keep on traversing
    the list. While traversing, we maintain a data structure to store the traversed nodes. Hence,
    at each node, we first check if the current node is in the traversed nodes or not. If yes, then
    that means there is a cycle in the linked list and we return true. Otherwise, we simply insert it
    in our data strcture. If our current pointer reaches the end of the list, then it implies that 
    there was no cycle in the linked list and we return false.
    Time complexity :- O(N)
    Space complexity :- O(N)

    Code :-
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(head==NULL || head->next==NULL){
                return false;
            }
            
            set<ListNode*>s;
            ListNode* cur = head;
            while(cur!=NULL){
                if(s.find(cur)!=s.end()){
                    return true;
                }
                s.insert(cur);
                cur=cur->next;
            }
            
            return false;
        }
    };
*/

//Efficient Approach :-
/*
    We can optimsie the naive solution in terms of space complexity. Instead of using extra space
    to store the traversed nodes, we use two pointers first and second.We move the second pointer 
    twice as fast as the first one, until it is not null. If the first and second pointers meet, 
    then it means that we have a cycle. Otherwise if the second point becomes null, it means there is
    no cycle in list.

    Time Complexity :- O(N)
    Space Complexity :- O(1)
*/

//Code :-
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode* first = head;
        ListNode* second = head;
        while(second!=NULL && second->next!=NULL){
            first = first->next;
            second = second->next->next;
            if(first==second){
                return true;
            }
        }
        
        return false;
    }
};