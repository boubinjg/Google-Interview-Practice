#include<iostream>
#include<queue> 
struct node{
	int val;
	node* left;
	node* right;
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
bool bfs(node* root, node* goal)
{
	std::queue<node*> q;
	q.push(root);

	while(!q.empty())
	{
		node* cur = q.front();
		q.pop();
		if(cur->left == goal)
			return true;
		else if(cur->left != NULL)
			q.push(cur->left);
		if(cur->right != NULL && cur->right == goal)
			return true;
		else if(cur->right != NULL)
			q.push(cur->right);
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

	std::cout<<bfs(root, ur)<<" "<<bfs(root,a)<<" "<<bfs(a, b)<<std::endl;

	return 0;
}
