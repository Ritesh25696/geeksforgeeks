/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node  
struct Node {
    int data;
    Node* next;
}; */
Node* SortedMerge(Node* head1,   Node* head2)
{
    Node* res = new Node;
    if(head1 == NULL)return head2;
    else if(head2 == NULL)return head1;
    else if(head1->data <= head2->data){
        res->data = head1->data;
        res->next = SortedMerge(head1->next,head2);
    }
    else{
        res->data = head2->data;
        res->next = SortedMerge(head1,head2->next);
    }
    return res;
}
