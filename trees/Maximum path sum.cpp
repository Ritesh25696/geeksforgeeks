Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting number of nodes. Second line of every test case consists of N Spaced 3 elements, Parent node data, child node data and position of child node( 'L'  or  'R' ).

Output:
Return the Maximum possible sum.

Constraints:
1<=T<=100
1<=N<=30

Example:
Input:
1
12
-15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 -3 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L
Output:
27

**************************************************************************************************************************************

int util(Node* root , int& maxsum){
    if(root == NULL)return 0;
    int l = util(root->left , maxsum);
    int r = util(root->right , maxsum);
    int maxs = max(max(l,r)+root->data , root->data);
    int res = max(maxs , l+r+root->data);
    maxsum = max(maxsum , res);
    return maxs;
}

int maxPathSum(struct Node *root)
{
int maxsum = INT_MIN;
util(root , maxsum);
return maxsum;
    
}
