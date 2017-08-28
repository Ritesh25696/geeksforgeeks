Given a binary tree, return true if it is BST, else false. For example, the following tree is not BST, because 11 is in left subtree of 10.

        10
     /     \
   7       39
     \
      11

 

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return 1 if BST else return 0.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
0
0
*********************************************************************************************

void inorder(Node *root , vector<int> &A){
    if(root == NULL)return;
    inorder(root->left,A);
    A.push_back(root->data);
    inorder(root->right,A);
}

bool isBST(Node* root) {
   vector<int> a;
   inorder(root , a);
   vector<int> b ;
   for(int i=0 ; i<a.size() ; i++)b.push_back(a[i]);
   sort(a.begin(), a.end());
   for(int i=0 ; i<a.size() ; i++){
       if(a[i] != b[i])return false;
   }
   return true;
}
