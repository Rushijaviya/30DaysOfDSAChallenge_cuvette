//Nth node from end of linked list
//https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

//Approach 1 :-
/*
    We first find the lenght of the linked list. Then, we know that nth node from the end of 
    linked list will be the (length - n +1)th node from the beginning. Hence we again traverse 
    the linked list until we reach the (lenght - n + 1)th node from the beginning.
    Time Complexity :- O(N)
    Space Complexity :- O(1)

    Code :-
    int getNthFromLast(Node *head, int n)
    {
        // Your code here
        Node* cur = head;
        int length = 0;
        while(cur!=NULL){
            cur = cur->next;
            ++length;
        }
        if(n > length){
            return -1;
        }
        cur = head;
        int nodesToTraverse = length - n;
        while(nodesToTraverse > 0){
            cur = cur->next;
            --nodesToTraverse;
        }
        return cur->data;
        
    }
*/




//Approach 2:-
/*
    The first approach is a two pass solution. We can also solve the problem in one pass by the use
    of two pointers.
    To find the nth node from the end of a linked list, we use two pointers, each of them initially
    pointing to the head of the linked list. Then we traverse the linked list and for the first n 
    iterations keep moving the first pointer forward. After that we move both the pointers simultaneously.
    Hence when the first pointer reaches the end of the linked list, the second pointer would be pointing
    to the n-th node form the end of linked list.
    Time Complexity :- O(N)
    Space Complexity :- O(1)
*/

//Code :-
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node* cur1 = head;
       Node* cur2 = head;
       
       int i = 0;
       while(cur1!=NULL){
           if(i<n){
               cur1= cur1->next;
               i++;
               if(cur1==NULL && i!=n){
                   return -1;
               }
           }
           else{
               i++;
               cur1 = cur1->next;
               cur2= cur2->next;
           }
       }
       return cur2->data;
}
