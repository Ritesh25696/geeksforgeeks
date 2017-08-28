
Write a function to print spiral order traversal of a tree. For below tree, function should print 1, 2, 3, 4, 5, 6, 7.


 
 

Input:
The task is to complete the method which takes one argument, root of the Tree. The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print level order traversal in spiral form .

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 3000
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 3 2
10 20 30 60 40
*******************************************************************************************************

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
void printSpiral(Node *A)
{

    stack<Node *> S;
    cout<<A->data<<" ";
    stack<Node*> temp;
    bool ltor = false;
    if(A->right) S.push(A->right);
    if(A->left) S.push(A->left);
    while(!S.empty()){

        Node* cur = S.top();
        if(ltor){
        if(cur->right)temp.push(cur->right);
        if(cur->left)temp.push(cur->left);}
        if(!ltor){
        if(cur->left)temp.push(cur->left);
        if(cur->right)temp.push(cur->right);
        }
        cout<<cur->data<<" ";
        S.pop();
        if(S.empty()){
            S = temp;
            while(!temp.empty())temp.pop();
            if(ltor)ltor = false;
            else ltor = true;
        }
    }
}
