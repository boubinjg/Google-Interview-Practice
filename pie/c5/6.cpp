#include<iostream>
#include<vector>
#include<algorithm>
struct node{
	node* left;
	node* right;
	int val;
};
void print(node* root)
{
	if(root != NULL)
	{
		print(root->left);
		std::cout<<root->val<<std::endl;
		print(root->right);
	}
}
void getTree(node* root, std::vector<int>& v)
{
	if(root != NULL)
	{
		v.push_back(root->val);
		getTree(root->left,v);
		getTree(root->right,v);
	}
} 
void printVec(std::vector<int> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<std::endl;
	std::cout<<std::endl;
}
node* vecToTree(std::vector<int> v)
{
	if(v.size() == 0)
	{
		return NULL;
	}
	else if(v.size() == 1)
	{
		node* root = new node;
		root->val = v[0];	
		std::cout<<"1 "<<v[0]<<std::endl;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else
	{
		auto middle = v.begin() + v.size()/2;
		node* root = new node;
		root->val = *middle;
		std::vector<int> left(v.begin(), middle);
		std::vector<int> right(middle+1, v.end());
		
		root->left = vecToTree(left);
		root->right = vecToTree(right);
		return root;
	}
}
void rebalance(node* root)
{
	std::vector<int> tree;
	getTree(root, tree);
	std::sort(tree.begin(), tree.end());
	node* newRoot = vecToTree(tree);
	print(newRoot);
}
int main()
{
	node* root = new node;
	node* a = new node;
	node* b = new node;
	node* c = new node;
	node* d = new node;
	node* e = new node;

	root->val = 10;
	a->val = 7;
	b->val = 15;
	c->val = 5;
	d->val = 9;
	e->val = 0;

	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	c->left = e;
	rebalance(root);
	
	return 0;
}
