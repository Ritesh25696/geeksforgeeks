
Given a linked list of 0s, 1s and 2s, sort it.

Input:

Complete the method which takes one argument: the head of the linked list. The program should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output: The function should not print any output to stdin/console.
 

Example:

Input:
1 2 2 1 2 0 2 2

Output:
0 1 1 2 2 2 2 2 

For Testing(format):

1(Test cases)
8(Number of elements in Link List)
1 2 2 1 2 0 2 2 

******************************************************************************************************************

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     Node *next;
  }
*/

void sortList(Node *head)
{
  int count[3] = {0, 0, 0}; 
    struct Node *ptr = head;
 
    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }
 
    int i = 0;
    ptr = head;
 
    while (ptr != NULL)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}
