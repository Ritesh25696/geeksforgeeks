Given a binary tree, your task is to complete the function verticalOrder which takes one argument the root of the binary tree and prints the node of the binary tree in vertical order .

          1
       /     \
     2       3
   /        /
4       5

The nodes of the above tree printed in vertical order will be
4
2
1 5
3
Your output should be 4 $2 $1 5 $3 $

Note: Each vertical line will be separated by a "$" without quotes.

Input:

The task is to complete the method which takes one argument, root of Binary Tree. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print nodes in vertical order where  each vertical line is separated by a "$" without quotes.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 20
 

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 $1 $2 $
40 $20 $10 60 $30 $
******************************************************************************************************************************************

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/* Should print vertical order such that each vertical line
   is separated by $ */
void findMinMax(Node *node, int *min, int *max, int hd)
{
    if (node == NULL) return;
    if (hd < *min)  *min = hd;
    else if (hd > *max) *max = hd;
    findMinMax(node->left, min, max, hd-1);
    findMinMax(node->right, min, max, hd+1);
}

void printVerticalLine(Node *node, int line_no, int hd)
{
    if (node == NULL) return;
 
    if (hd == line_no)
        cout << node->data <<" ";
    printVerticalLine(node->left, line_no, hd-1);
    printVerticalLine(node->right, line_no, hd+1);
}
 
   
void verticalOrder(Node *root)
{
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);
    for (int line_no = min; line_no <= max; line_no++)
    {
        printVerticalLine(root, line_no, 0);
        cout << "$";
    }
}
