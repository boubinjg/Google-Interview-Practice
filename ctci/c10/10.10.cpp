#include<iostream>
#include<algorithm>
#include<vector>
struct node{
	node* left;
	node* right;
	int val;
};
class bst{
private:
	node* root;
	void insertNode(node* n, node* r)
	{
		if(r == NULL)
			r = n;
		
		else if(n->val > root->val)
		{
			if(root->right == NULL)
				r->right = n;
			else
				insertNode(r->right, n);
		}
		else if(n->val < root->val)
		{
			if(r->left = NULL)
				r->left = n;
			else
				insertNode(r->left, n);
		}	
	}
	int inorder(int val, node* n)
	{
		
		if(n != NULL)
		{
			std::cout<<n->val<<std::endl;
			int v = inorder(val, n->left);
			if(n->val < val)
				return v + 1;
			if(v > 0)
				return v;
			else
				return inorder(val, n->right);
			
		}
		return 0;
	}
	
public:
	bst()
	{
		root = NULL;
	}
	void insert(int val)
	{
		node* n = new node;
		n->val = val;
		n->left = NULL;
		n->right = NULL;
		
		insertNode(n, root);
	}
	int degree(int val)
	{
		return inorder(val, root);
	}
};
int main()
{
	bst b;
	b.insert(3);
	b.insert(2);
	b.insert(1);
	b.insert(4);
	b.insert(5);

	std::cout<<b.degree(3)<<std::endl;	
}
