// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

int difference(Node *head1, Node *head2);

int intersectPoint(Node* head1, Node* head2)
{
    if(head1 == NULL || head2 == NULL)
        return -1;
        
    int diff = difference(head1, head2);
    
    if(diff < 0)
        while(diff++ != 0)
            head2 = head2 -> next;
    else
        while(diff-- != 0)
            head1 = head1 -> next;
            
    while(head1 != NULL)
    {
        if(head1 == head2)
            return head1 -> data;
            
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    
    return -1;
}

int difference(Node *head1, Node *head2)
{
    int l1 = 0, l2 = 0;
    
    while(head1 != NULL || head2 != NULL)
    {
        if(head1 != NULL)
        {
            l1++;
            head1 = head1 -> next;
        }
        
        if(head2 != NULL)
        {
            l2++;
            head2 = head2 -> next;
        }
    }
    
    return l1 - l2;
}
