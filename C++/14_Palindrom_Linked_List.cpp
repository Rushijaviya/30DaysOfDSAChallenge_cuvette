//234. Palindrome Linked List
//https://leetcode.com/problems/palindrome-linked-list/description/


//Naive Approach :-
/*
    The brute force approach for the problem can be to traverse the linked list, and keep storing 
    the values of the nodes in another data structure(like vector). Then we can find if the vector
    is a palindrome. 
    Time Complexity:- O(N)
    Space Complexity :- O(N)

    Code :-
    class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if(head==NULL || head->next==NULL){
                return true;
            }
            
            vector<int>v;
            while(head!=NULL){
                v.push_back(head->val);
                head = head->next;
            }
            
            int i =0, j = (int)v.size()-1;
            while(i<=j){
                if(v[i]!=v[j]){
                    return false;
                }
                i++;
                j--;
            }
            
            return true;
        }
    };
*/


//Efficient Approach:-
/*
    The brute force approach uses extra space to store the values of each of the nodes. We can
    get rid of the extra space complexity. To do this, we first fidn the middle of the linked list
    by fast and slow pointer method. Then we reverse the second half of the linked list(from middle node
    to end of linked list). 
    For eg :-
    Given Linked List :- 
    1 -> 2 -> 2 -> 1
    
    After reversing from the middle :-
    1 -> 2 -> 1 -> 2

    We can then use two pointers, one pointing to head and other pointing to 
    middle of the linked list initially to compare if the list is palindroe or not.
    
    Time Complexity :- O(N)
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
    ListNode* reverseList(ListNode* node){
        ListNode* prev = NULL;
        ListNode* cur = node;
        ListNode* nex = cur->next;
        
        while(nex!=NULL){
            cur->next = prev;
            prev = cur;
            cur = nex;
            nex = cur->next;
        }
        cur->next = prev;
        return cur;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        ListNode* temp = slow->next;
        while(temp!=NULL){
            if(head->val!=temp->val){
                return false;
            }
            head = head->next;
            temp = temp->next;
        }
        slow->next = reverseList(slow->next);
        return true;
    }
};