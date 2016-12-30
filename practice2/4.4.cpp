#include<iostream>
#include<queue>
#include<algorithm> 
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
balancedNode* checkDepth(node* n)
{
	if(n == NULL)
	{
		balancedNode* b = new balancedNode;
		b->depth = 1;
		b->balanced = true;
		return b;
	}
	balancedNode* bl = checkDepth(n->left);
	balancedNode* br = checkDepth(n->right);
	if(!bl->balanced)
		return bl;
	if(!br->balanced)
		return br;
	int depth;
	if(bl->depth > br->depth)
		depth = bl->depth;
	else
		depth = br->depth;
	
	balancedNode* ret = new balancedNode;
	if(std::abs(bl->depth-br->depth) > 1)
	{
		ret->balanced = false;
		return ret;
	}
	ret->balanced = true;
	ret->depth = 1+depth;
	return ret;
}
bool checkBalance(node* root)
{
	balancedNode* b = checkDepth(root);
	std::cout<<"depth: "<<b->depth<<std::endl;
	std::cout<<b->balanced<<std::endl;
	return b->balanced;
}
int main()
{
	node* root = new node;
	node* a = new node;
	node* b = new node;
	node* c = new node;
	node* d = new node;
	node* e = new node;

	root->left = a;
	root->right = b;
	
	a->left = c;
	a->right = d;
	
	c->left = e;

	root->val = 0;
	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 4;
	e->val = 5;
	
	inorder(root);	

	node* ur = new node;

	std::cout<<checkBalance(root)<<" "<<checkBalance(b);

	return 0;
}
