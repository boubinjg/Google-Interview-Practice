#include<iostream>
struct node{
	node* left;
	node* right;
	int val;
};
int findDepth(node* root)
{
	if(root != NULL)
	{
		int ls = findDepth(root->left);
		int rs = findDepth(root->right);
		if(ls > rs)
			return 1+ls;
		else
			return 1+rs;
	}
	return 0;
}
int main()
{
	node* root = new node;
	node* a = new node;
	node* b = new node;
	node* c = new node;
	node* d = new node;
	node* e = new node;

	root->val = 0;
	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 4;
	e->val = 5;

	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	c->right = e;

	std::cout<<findDepth(root)<<std::endl;
}
