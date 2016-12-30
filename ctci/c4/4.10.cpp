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
void preorder(node* root, std::string& s)
{
	if(root != NULL)
	{
		s+=std::to_string(root->val);
		s+=",";
		preorder(root->left, s);
		preorder(root->right, s);
	}
	else
		s+="X";
}
bool containsSubtree(node* t1, node* t2)
{
	if(t2 != NULL)
	{
		if(t2->val == t1->val)
		{
			std::string s1, s2;
			preorder(t1, s1);
			preorder(t2, s2);
			if(s1 == s2)
				return true;
		}
		return containsSubtree(t1, t2->left) || containsSubtree(t1, t2->right);
	}
	return false;
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
	
	std::cout<<containsSubtree(A, root)<<" "<<containsSubtree(D, A)<<std::endl;
}
