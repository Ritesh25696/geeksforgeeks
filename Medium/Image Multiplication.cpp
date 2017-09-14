You are given a binary tree. Your task is pretty straightforward. You have to find the sum of the product of each node and its mirror image (The mirror of a node is a node which exists at the mirror position of the node in opposite subtree at the root.). Don’t take into account a pair more than once. The root node is the mirror image of itself.

 

Input:

The first line consists of an integer T denoting the number of test cases. Each test case consists of two lines. The first line of each test case consists of a single integer N, denoting the number of edges in Binary tree. The next line contains the edges of the binary tree. Each edge consists of two integers and one character first of whose is parent node, second is child node and character "L" representing Left child and "R" representing the right child. 

 

Output:

For each test case, print in a new line the required sum. As the results can be large, print your result modulo 10^9 + 7 
 

Constraints:

1 <= T <= 1000             

1 <= N <= 10^5 
 

Example:

Input:

2

12

1 2 R 1 3 L 2 5 L 2 4 R 3 6 R 3 7 L 5 9 L 5 8 R 7 10 R 7 11 L 4 12 R 6 15 R

2

4 5 L 4 6 R

Output:

332

46

Explanation:

The tree for the 1st case is–

                                       1                  

                         /                               \

                 3                                           2

            /           \                             /            \

       7                    6                   5                   4

   /      \                    \               /       \                    \

11       10                15         9             8                 12

Sum = (1*1) + (3*2) + (7*4) + (6*5) + (11*12) + (15*9) = 332

 

The tree for the 2nd case is-      

          4         

    /            \

5                   6

Sum = (4*4) + (5*6) = 46
***********************************************************************************************************************************************************************


#include <iostream>
#include <map>
#define mod 1000000007
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node *new_node (int data) {
	Node *node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

Node* make_tree (int n) {
	map <int, Node*> store;
	cin >> n;
	int parent, child;
	char dir;
	Node *root, *par, *chi;
	for (int i=0; i<n; ++i) {
		cin >> parent >> child >> dir;
		if (store.find (parent) == store.end ()) {
			store [parent] = new_node (parent);
		}
		store [child] = new_node (child);
		if (dir == 'R') store [parent] -> right = store [child];
		else if (dir == 'L') store [parent] -> left = store [child];
		
		if (! i) root = store [parent];
	}
	return root;
}

int image_multiplication (Node *left, Node *right) {
	if (left != NULL && right != NULL) {
		int sum_left = image_multiplication (left->left, right->right);
		int sum_right = image_multiplication (left->right, right->left);
		return ((left->data * right->data) % mod + (sum_left + sum_right)) % mod;
	} else {
		return 0;
	}
}

void inorder (Node *root) {
	if (root == NULL) return;
	inorder (root->left);
	cout <<root->data<<" ";
	inorder (root->right);
}

int main () {
	int t, n;
	cin >> t;
	while (t--) {
		Node* root = make_tree (n);
		if (root != NULL) cout << (image_multiplication (root->left, root->right) + (root->data * root->data)) % mod;
		cout <<endl;
	}
	return 0;
}
