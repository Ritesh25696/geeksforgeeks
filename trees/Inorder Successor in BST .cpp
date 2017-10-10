/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of Node
struct Node {
int data;
Node * right, * left;
};*/
/* The below function should return the node which is 
inorder successor of given node x. */
void succ(Node * root , Node * x ,Node*& res){
    if(root == NULL){res = NULL;return;}
    if(root -> data == x->data){
        if(root->right != NULL){
            Node * temp = root->right;
            while(temp->left != NULL)temp = temp->left;
            res = temp;
            return;
        }
    }
    if(root->data > x->data){
        res = root;
        succ(root->left, x , res);
    }
    else if(root->data < x->data)
    succ(root->right , x , res);
}

Node * inOrderSuccessor(Node *root, Node *x)
{
 Node * res = NULL;
 succ(root , x , res);
 return res;
    
}
