#include<iostream>
#include<stack>
struct node{
	node* left;
	node* right;
	int val;
};
bool exists(node* root, node* a)
{
	if(root != NULL)
	{
		if(root == a)
			return true;
		else
			return exists(root->left, a) || exists(root->right, a);
	}
	return false;
}
void LCA(node* root, node* a1, node* a2)
{
	if(a1 == a2 && exists(root, a1))
		std::cout<<a1->val<<std::endl;
	if(root != NULL)
	{
		bool l1 = exists(root->left,a1), l2 = exists(root->left,a2);
		if(l1 && l2)
			LCA(root->left, a1, a2);
		else if(l1 || l2)
			std::cout<<root->val<<std::endl;
		else
			LCA(root->right, a1, a2);
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
	LCA(root, a, c);
	return 0;
}
