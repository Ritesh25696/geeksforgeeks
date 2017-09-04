
There are two singly linked lists in a system. By some programming error the end node of one of the linked list got linked into the second list, forming a inverted Y shaped list. Write a program to get the point where two linked lists merge.

Y ShapedLinked List
Above diagram shows an example with two linked list having 15 as intersection point.

Expected time complexity is O(m + n) where m and n are lengths of two linked lists

Input:

You have to complete the method which takes two arguments as heads of two linked lists. 


Output:
The function should return data value of a node where two linked lists merge.  If linked list do not merge at any point, then it shoudl return -1.

Constraints:
1 <=T<= 50
1 <=N<= 100
1 <=value<= 1000

Example:
Input:
2
2 3 2
10 20
30 40 50
5 10
2 3 0
10 20
30 40 50
First line is number of test cases. Every test case has four lines. First line of every test case contains three numbers, x (number of nodes before merge point in 1st list), y(number of nodes before merge point in 11nd list) and z (number of nodes after merge point).  Next three lines contain x, y and z values.

Output:
5
-1

***************************************************************************************************************************
/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node 
struct Node {
    int data;
    struct Node* next;
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
   #include<set>
int intersectPoint(Node* head1, Node* head2)
{
    set<Node*> myset;
    while(head1 != NULL){
    myset.insert(head1);
    head1 = head1->next;    
    }
    while(head2 != NULL){
        if(myset.find(head2) != myset.end())return head2->data;
        head2 = head2->next;
    }
    return -1;
}
