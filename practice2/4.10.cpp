#include<iostream>
#include<queue>
#include<algorithm> 
#include<queue>
struct node{
	int val;
	node* left;
	node* right;
};
struct balancedNode{
	int depth;
	bool balanced;
};
void inorder(node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		std::cout<<root->val<<std::endl;
		inorder(root->right);
	}
}

bool sameTree(node* t1, node* t2)
{
	if(t1 != NULL && t2 != NULL)
	{
		bool r = sameTree(t1->right, t2->right);
		bool l = sameTree(t1->left, t2->left);
		if(t1->val != t2->val)
			return false ;
		return l&&r;
	}
	if(t1 != NULL || t2 != NULL)
	{
		return false;
	}
	return true;
}
bool checkSubtree(node* t1, node* t2)
{
	std::queue<node*> q;
	q.push(t1);
	
	while(!q.empty())
	{
		node* cur = q.front();
		q.pop();
		if(cur->val == t2->val && sameTree(cur, t2))
			return true;
		if(cur->right != NULL)
			q.push(cur->right);
		if(cur->left != NULL)
			q.push(cur->left);
	}
	return false;
}
int main()
{
	node* root = new node;
	node* a = new node;
	node* b = new node;
	node* c = new node;
	node* d = new node;
	node* e = new node;

	root->left = a;
	root->right = b;
	
	a->left = c;
	a->right = d;
	
	c->left = e;

	root->val = 0;
	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 4;
	e->val = 5;
	
	inorder(root);	

	node* ur = new node;

	std::cout<<checkSubtree(root, root)<<" "<<checkSubtree(root,a)<<" "<<checkSubtree(root,ur)<<std::endl;

	return 0;
}
