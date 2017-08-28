Given a Binary Search Tree and 2 nodes value n1 and n2  , your task is to find the lowest common ancestor of the two nodes . You are required to complete the function LCA . You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.
*********************************************************************************************************

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/
/*You are required to complete
this function*/
Node* LCA(Node *root, int n1, int n2)
{
    if(n1<root->data && n2<root->data)return LCA(root->left,n1,n2);
    if(n1>root->data && n2>root->data)return LCA(root->right,n1,n2);
    return root;
}
