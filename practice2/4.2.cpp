//extra credit
#include<vector>
#include<iostream>
struct node{
	node* left;
	node* right;
	int val;
};
void inorder(node* n)
{
	if(n != NULL)
	{
		inorder(n->left);
		std::cout<<n->val<<std::endl;
		inorder(n->right);
	}
}
node* buildTree(std::vector<int> v)
{
	if(v.size() == 0)
	{
		return NULL;
	}
	if(v.size() == 1)
	{
		node* root = new node;
		root->val = v[0];
		return root;
	}
	if(v.size() == 2)
	{
		node* root = new node;
		root->val = v[1];
		root->left = new node;
		root->left->val = v[0];
		return root;
	}
	else
	{
		node* root = new node;
		auto middle = v.begin() + v.size()/2;
		std::vector<int> left(v.begin(), middle);
		std::vector<int> right(middle+1, v.end());
		root->left = buildTree(left);
		root->right = buildTree(right);
		root->val = *middle;
		return root;
	}
}
int main()
{
	std::vector<int> v;
	for(int i = 1; i<=20; i++)
	{
		v.push_back(i);
	}

	node* root = new node;
	root = buildTree(v);
	std::cout<<root->val<<std::endl;
	std::cout<<std::endl;
	inorder(root);
}
