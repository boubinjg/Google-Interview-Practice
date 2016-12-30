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
	std::vector<int> right(list.begin(), middle);
	std::vector<int> left(middle+1, list.end());
	
	root->right = makeBTree(right);
	root->left = makeBTree(left);

	return root;
}
int sumCount(node* root, int val, int count)
{
	if(root == NULL)
	{
		return count == val;
	}
	count += root->val;
	return sumCount(root->left, val, count) + sumCount(root->right, val, count);
}
int sumToVal(node* root, int val)
{
	return sumCount(root, val, 0);	
}
int main()
{
	std::vector<int> v;
	for(int i = 1; i<4; i++)
	{
		v.push_back(i);
	}
	node *root = makeBTree(v);
	
	std::cout<<sumToVal(root, 3)<<std::endl;
}
