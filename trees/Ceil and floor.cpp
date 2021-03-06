// Program to find ceil of a given value in BST
#include <stdio.h>
#include <stdlib.h>
#define data key
#include<iostream>
using namespace std;
/* A binary tree node has key, left child and right child */
struct node
{
	int key;
	struct node* left;
	struct node* right;
};


struct node* newNode(int key)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
int f=-1,c=-1;
void ceilfloor(node *root,int k)
{
    if(root==NULL) return;
    if(root->data==k){c=f=k;}
    if(root->data<k){f=root->data;ceilfloor(root->right,k);}
    if(root->data>k){c=root->data;ceilfloor(root->left,k);}
}
// Driver program to test above function
int main()
{
	node *root = newNode(8);

	root->left = newNode(4);
	root->right = newNode(12);

	root->left->left = newNode(2);
	root->left->right = newNode(6);

	root->right->left = newNode(10);
	root->right->right = newNode(14);

	ceilfloor(root , 11);
	cout<<f<<" "<<c<<endl;

	return 0;
}
