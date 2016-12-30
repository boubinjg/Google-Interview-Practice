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
bool bfs(node *root, node *g)
{
	std::queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* n = q.front();
		q.pop();
		if(n == g)
		{
			std::cout<<"1"<<std::endl;
			return true;
		}
		if(n->left != NULL)
			q.push(n->left);
		if(n->right != NULL)
			q.push(n->right);
	}
	return false;
}
node* lca(node *n, node *m, node *root)
{
	bool mroute = bfs(root->left, m);
	bool nroute = bfs(root->left, n);
	
	if(mroute && nroute)
		return lca(m, n, root->left);
	else if(!mroute && !nroute)
		return lca(m, n, root->right);
	return root;
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

	std::cout<<lca(B,C, root)->val<<std::endl;
}
