/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/
/*You are required to complete this method */
Node* getnewnode(int x){
    Node* temp = new Node;
    temp->left = NULL;
    temp->right = NULL;
    temp -> data = x;
    temp->height = 1;
    return temp;
}

int height(Node * x){
    if(x == NULL)return 0;
    return x->height;
}

int getbalance(Node* x){
    if(x == NULL)return 0;
    return height(x->left)-height(x->right);
}

Node *rightrotate( Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
Node *leftrotate( Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
Node* insertToAVL( Node* node, int data)
{
       if(node == NULL){
        Node* temp = getnewnode(data);
        return temp;
    }
    if(data < node->data){
        node->left = insertToAVL(node->left , data);
    }
    else if(data > node->data){
        node->right = insertToAVL(node->right , data);
    }
        
    node->height = max(height(node->left),height(node->right))+1;
    int balance = getbalance(node);
    
    if (balance > 1 && data < node->left->data)
        return rightrotate(node);
    
    else if(balance > 1 && data>node->left->data){
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    else if(balance<-1 && data>node->right->data)
        return leftrotate(node);

    else if (balance < -1 && data < node->right->data)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
 
    return node;
 
  
}
