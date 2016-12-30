#include<iostream>
#include<queue>
#include<algorithm> 
#include<queue>
struct node{
	int val;
	node* left;
	node* right;
};
struct balancedNode{
	int depth;
	bool balanced;
};
void inorder(node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		std::cout<<root->val<<std::endl;
		inorder(root->right);
	}
}
int sumPaths(node* root, int val, int cval)
{
	if(root != NULL)
	{
		cval += root->val;
		int retVal = 0;
		if(cval == val)
		{
			retVal=1;
			std::cout<<root->val<<std::endl;
		}
		return retVal + sumPaths(root->left,val,cval) + sumPaths(root->right,val,cval) + sumPaths(root->left,val,0) + sumPaths(root->right,val,0);
	}
}
int main()
{
	node* root = new node;
	node* a = new node;
	node* b = new node;
	node* c = new node;
	node* d = new node;
	node* e = new node;
	node* f = new node;
	
	root->left = a;
	root->right = b;
	
	a->left = c;
	a->right = d;
	b->left = e;
	b->right = f;
	
	
	root->val = 3;
	a->val = 1;
	b->val = 5;
	c->val = 0;
	d->val = 2;
	e->val = 4;
	f->val = 6;
	
	//inorder(root);	
	
	node* ur = new node;

	std::cout<<sumPaths(root, 4, 0)<<std::endl;
	return 0;
}
