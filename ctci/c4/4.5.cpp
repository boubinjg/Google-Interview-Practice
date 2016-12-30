#include<vector>
#include<iostream>
#include<algorithm>
#include<limits.h>
struct node{
	node* left;
	node* right;
	int val;
};
node* makeBTree(std::vector<int> list)
{
	//std::cout<<list.size()<<std::endl;
	if(list.size() == 0)
		return NULL;
	if(list.size() == 1)
	{
		node *n = new node;
		n->val = list[0];
		n->right = NULL;
		n->left = NULL;
	}
	
	node *root = new node;	
	root->val = list[list.size()/2];
	std::vector<int>::iterator middle = (list.begin() + list.size()/2);
	std::vector<int> left(list.begin(), middle);
	std::vector<int> right(middle+1, list.end());
	
	root->right = makeBTree(right);
	root->left = makeBTree(left);

	return root;
}
int max(node* root)
{
	if(root = NULL)
		return 0;
	if(root->right == NULL)
		return root->val;
	return max(root->right);
}
void inorder(node* root, std::vector<int>& v)
{
	if(root != NULL)
	{
		inorder(root->left, v);
		v.push_back(root->val);
		inorder(root->right, v);
	}
}
bool checkOrder(std::vector<int> v)
{
	for(int i = 0; i<v.size()-1; i++)
	{
		if(v[i] > v[i+1])
			return false;
	}
	return true;
}
int main()
{
	std::vector<int> v;
	for(int i = 0; i<20; i++)
	{
		v.push_back(i);
	}
	node *root = makeBTree(v);
	node *root2 = new node;
	node *rootA = new node;
	node *rootB = new node;
	root2 ->right = rootA;
	root2 ->left = NULL;
	rootA ->right = rootB;
	rootA ->left = NULL;
	rootB ->right = NULL;
	rootB ->left = NULL;
	
	v.clear();
	inorder(root, v);
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
	std::cout<<checkOrder(v)<<std::endl;
	
}
