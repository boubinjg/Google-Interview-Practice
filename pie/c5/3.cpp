#include<iostream>
#include<stack>
struct node{
	node* left;
	node* right;
	int val;
};
void preorder(node* root)
{
	std::stack<node*> rightStack;
	rightStack.push(NULL);
	while(root != NULL)
	{
		node* cur = root;
		while(cur != NULL)
		{
			std::cout<<cur->val<<" ";
			if(cur->right != NULL)
				rightStack.push(cur->right);
			cur = cur->left;
		}
		root = rightStack.top();
		rightStack.pop();
	}
	std::cout<<std::endl;
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

	preorder(root);
}
