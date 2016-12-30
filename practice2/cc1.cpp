#include<iostream>
#include<queue> 
#include<vector>
struct node{
	int val;
	std::vector<node*> nlist;
};
/*void inorder(node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		std::cout<<root->val<<std::endl;
		inorder(root->right);
	}
}*/
int height(node* root)
{
	if(root != NULL)
	{
		int theight = 0;
		for(auto it = root->nlist.begin(); it<root->nlist.end(); *it++)
		{
			int cheight = height(*it);
			if(cheight > theight)
				theight = cheight;
		}
		return 1+theight;
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

	root->nlist.push_back(a);
	root->nlist.push_back(b);
	root->nlist.push_back(c);

	a->nlist.push_back(d);
	d->nlist.push_back(e);
	
	root->val = 0;
	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 4;
	e->val = 5;

	node* ur = new node;

	std::cout<<height(root)<<std::endl;
	return 0;
}
