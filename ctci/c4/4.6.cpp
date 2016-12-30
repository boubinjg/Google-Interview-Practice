#include<vector>
#include<iostream>
#include<algorithm>
#include<limits.h>
struct node{
	node* left;
	node* right;
	node* parent;
	int val;
};
node* getLeftmost(node* root)
{
	if(root->left == NULL)
		return root;
	else
		return getLeftmost(root->left);
	
}
node* checkParent(node* root, node* parent)
{
	if(root == parent->left)
		return parent;
	else
		return checkParent(parent, parent->parent);
}	
node* inorderSuccessor(node* root)
{
	if(root->right != NULL)
	{
		return getLeftmost(root->right);
	}
	else if(root->parent->left == root)
		return root->parent;
	else
	{
		return checkParent(root->parent, root->parent->parent);	
	}
}
void inorder(node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		std::cout<<root->val<<std::endl;
		inorder(root->right);
	}
}
int main()
{
	
	node *root = new node;
	node *A = new node;
	node *B = new node;
	node *C = new node;
	node *D = new node;
	root->left = A;
	root->right = D;
	root->val = 5;
	A ->left = B;
	A ->right = C; 
	A ->val = 2;
	A ->parent = root;
	B ->left = NULL;
	B ->right = NULL;
	B ->val = 0; 
	B -> parent = A;
	C ->left = NULL;
	C ->right = NULL;
	C ->val = 3;
	C ->parent = A;
	D ->parent = root;
	D ->left = NULL;
	D ->right = NULL;
	D ->val = 20;

	std::cout<<inorderSuccessor(B)->val<<std::endl;
}
