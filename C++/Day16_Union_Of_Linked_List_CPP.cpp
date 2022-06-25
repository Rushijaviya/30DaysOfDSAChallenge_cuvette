
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
