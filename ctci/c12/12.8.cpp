//create a method which deep copies a binary tree from a node n.
#include<iostream>
struct node{
	node* right;
	node* left;
	int val;
};
void inOrder(node* n)
{
	if(n != NULL)
	{
		inOrder(n->left);
		std::cout<<n->val<<" ";
		inOrder(n->right);
	}
}
node* deepcopy(node* r)
{
	if(r == NULL)
		return NULL;
	node* n = new node;
	n->val = r->val;
	n->left = deepcopy(r->left);
	n->right = deepcopy(r->right);
	return n;
}
int main()
{
	node* n1 = new node;
	node* n2 = new node;
	node* n3 = new node;
	node* n4 = new node; 

	n1->left = n2;
	n1->right = n3;
	n1->val = 1;
	
	n2->left = n4;
	n2->right = NULL;
	n2->val = 2;
	
	n3->left = NULL;
	n3->right = NULL;
	n3->val = 3;
	
	n4->left = NULL;
	n4->right = NULL;
	n4->val = 4;

	inOrder(n1);
	std::cout<<std::endl;
	node* n5 = deepcopy(n1);
	inOrder(n2);
	std::cout<<std::endl;
}
