#include<vector>
#include<iostream>
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
void preorder(node* root)
{
	if(root != NULL)
	{
		std::cout<<root->val<<" ";
		preorder(root->right);
		preorder(root->left);
	}
}
int main()
{
	std::vector<int> v;
	for(int i = 0; i<20; i++)
	{
		v.push_back(i);
	}
	node *root = makeBTree(v);
	preorder(root);
	std::cout<<std::endl;
}
