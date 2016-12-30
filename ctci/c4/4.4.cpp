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
	std::vector<int> right(list.begin(), middle);
	std::vector<int> left(middle+1, list.end());
	
	root->right = makeBTree(right);
	root->left = makeBTree(left);

	return root;
}
int checkDepth(node *root)
{
	if(root == NULL)
		return 0;
	int l = checkDepth(root->left) + 1;
	int r = checkDepth(root->right) + 1;
	if(std::abs(l-r) >1)
		return INT_MAX;
	else if(l>r)
		return l;
	return r;
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
	std::cout<<checkDepth(root)<<" "<<checkDepth(root2)<<std::endl;
}
