// Union of Two Linked Lists
// https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1

//Approach :-
/*
    The union of two linked lists contains all the values which are present in list1 and list2,
    ignoring the duplicate values. Additionally, we need to return the union list in sorted order.
    To solve the problem, we can traverse the lists given and store the elements in a set. Using a 
    set keeps the sorted order maintained while also ignoring the duplicate elements. Once we have 
    inserted all the elements in the set, we can make a new list and add all the values stored in the
    set to this result list.

*/

//Code :-

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    
    set<int> s; // using STL set
  // to avoid the use of STL we can modify the merge function of merge sort to keep only distinct elements
  //Try that yourself :)
    while(head1){
        s.insert(head1->data);
        head1= head1->next;
    }
    while(head2){
        s.insert(head2->data);
        head2 = head2->next;
    }
    struct Node* head=NULL;
    struct Node* ret;
    for(auto x : s){
        struct Node* newNode = new Node(x);
        if(!head){
            head=newNode;
            ret = head;
        }else{
            head->next = newNode;
            head= head->next;
        }
    }
    return ret;
    
}
