Write a function to connect all the adjacent nodes at the same level in a binary tree. Structure of the given Binary Tree node is like following.

 
struct Node{

  int data;

  Node* left;

  Node* right;

  Node* nextRight; 

}


Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.

Example:

Input Tree
       10
      / \
     3   5
    / \   \
   4   1   2


Output Tree
       10--->NULL
      / \
     3-->5-->NULL
    / \   \   
   4-->1-->2-->NULL
 

Input:

The task is to complete the method which takes one argument, root of Binary Tree. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should update nextRight pointers of all nodes.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
3 1 L 3 2 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 1 2
1 3 2
10 20 30 40 60
40 20 60 10 30
**************************************************************************************************************************************************************
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes
void connect(Node *p)
{
   queue<pair<Node*, int>> Q;
   p->nextRight = NULL;
   Node* prev = p;
   int dis = 0;
   if(p->left)Q.push(make_pair(p->left,1));
   if(p->right)Q.push(make_pair(p->right,1));
   while(!Q.empty()){
       
       pair<Node*,int> fr;
       fr = Q.front();
       Q.pop();
       Node* root = fr.first;
       int lvl = fr.second;
       if(dis == lvl){
           prev->nextRight = root;
       }
           root->nextRight = NULL;
           dis = lvl;
        if(root->left)Q.push(make_pair(root->left,lvl+1));
        if(root->right)Q.push(make_pair(root->right,lvl+1));
        prev = root;
   }
}
