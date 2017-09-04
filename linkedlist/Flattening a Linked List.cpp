
Given a Linked List where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node
(ii) a bottom pointer to a linked list where this node is head.

You have to flatten the linked list to a single linked list which is sorted.

For Ex: Shown below is a given linked list

           5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
and after flattening it, the sorted linked list looks like:

 5->7->8->10->19->20->22->28->30->35->40->45->50

The  node structure has 3 fields as mentioned. A next pointer, a bottom pointer and a data part.
There are multiple test cases. For each test case, this function will be called individually.

Note : All linked lists are sorted.

Input (To be used for Expected Output):
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer N denoting the number of head nodes connected to each other.
Second line of each test case contains N space separated numbers (M1, M2...Mn) denoting number of elements in linked lists starting with each head.
Third line of each test case contains all the elements of the linked list starting with 1st head node and covering all the elements through its down pointer, then 2nd head node and covering all its elements through down pointer and so on till the last head node of the linked list.

Output:
Return a pointer to the flattened linked list.

Constraints:

1<=T<=50
0<=N<=50
1<=Mi<=20
1<=Element of linked list<=1000

Example:
Input
1                   
4 
4 2 3 4                  
5 7 8 30 10 20 19 22 50 28 35 40 45

Output
5 7 8 10 19 20 22 28 30 35 40 45 50
****************************************************************************************************************************************

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
  struct Node* result = NULL;
 
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}
 

void FrontBackSplit(struct Node* source,
          struct Node** frontRef, struct Node** backRef)
{
  struct Node* fast;
  struct Node* slow;
  if (source==NULL || source->next==NULL)
  {   
    *frontRef = source;
    *backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}

void MergeSort(struct Node** headRef)
{
  struct Node* head = *headRef;
  struct Node* a;
  struct Node* b;
 
  if ((head == NULL) || (head->next == NULL))
  {
    return;
  }
 
 
  FrontBackSplit(head, &a, &b); 
 
 
  MergeSort(&a);
  MergeSort(&b);
 
 
  *headRef = SortedMerge(a, b);
}



Node *flatten(Node *root)
{
   Node *cur = root ,*next = NULL;
   while(cur != NULL){
       if(cur->bottom != NULL){
           next = cur->next;
           cur->next = cur->bottom;
           cur->bottom = NULL;
           cur = cur->next;
           while(cur->bottom != NULL){
               cur->next = cur->bottom;
               cur = cur->next;
           }
           cur->next = next;
       }
       else cur = cur->next;
   }
   cur = root;
   MergeSort(&cur);
   root = cur;

   while(cur != NULL){
       cur->bottom = cur->next;
       cur = cur->bottom;
   }
   return root;
}
