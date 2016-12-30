//this problem is super hard, come back to it later

#include<vector>
#include<iostream>
#include<algorithm>
#include<limits.h>
#include<queue>
struct node{
	node* left;
	node* right;
	node* parent;
	int val;
};
void print(std::vector<int> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
}
std::vector<int> combine(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> ret;
	for(int i = 0; i<left.size(); i++)
		ret.push_back(left[i]);
	for(int j = 0; j<right.size(); j++)
		ret.push_back(right[j]);
	return ret;
}
std::vector<std::vector<int> > weave(std::vector<int> left, std::vector<int> right)
{
	std::vector<std::vector<int> > ret;
	if(left.empty())
	{
		ret.push_back(right);
		return ret;
	}
	if(right.empty())
	{
		ret.push_back(left);
		return ret;
	}
	int lint = left.front();
	left.erase(left.begin());
	int rint = right.front();
	right.erase(right.begin());
	std::vector<std::vector<int> > left = weave(
}
std::vector<std::vector<int> > postOrder(node* root)
{
	std::vector<std::vector<int> > ret;
	if(root != NULL)
	{
		std::vector<std::vector<int> > left = postOrder(root->left);
		std::vector<std::vector<int> > right = postOrder(root->right);
		std::vector<std::vector<int> > ret = weave(left, right);
		for(auto it = ret.begin(); it<ret.end(); it++)
		{
			(*it).push_back(root->val);
			print((*it));
		}
	}
	return ret;	
}
int main()
{
	
	node *root = new node;
	node *A = new node;
	node *B = new node;
	node *C = new node;
	node *D = new node;
	root->left = A;
	root->right = D;
	root->val = 5;
	A ->left = B;
	A ->right = C; 
	A ->val = 2;
	A ->parent = root;
	B ->left = NULL;
	B ->right = NULL;
	B ->val = 0; 
	B -> parent = A;
	C ->left = NULL;
	C ->right = NULL;
	C ->val = 3;
	C ->parent = A;
	D ->parent = root;
	D ->left = NULL;
	D ->right = NULL;
	D ->val = 20;

	postOrder(root);
	/*
	for(auto it = v.begin(); it<v.end(); it++)
	{
		print(*it);
	}*/
}
