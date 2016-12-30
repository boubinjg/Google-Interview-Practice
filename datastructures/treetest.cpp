#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
struct node{
	int val;
	std::vector<node*> nodelist;
};
struct bnode{
	int val;
	bnode *left = NULL;
	bnode *right = NULL;
};
node* maketree()
{
	node* root = new node();
	root->val = 0;
	
	node *a = new node;
	a->val = 1;
	node *b = new node;
	b->val = 2;
	node *c = new node;
	c->val = 3;
	node *d = new node;
	d->val = 4;
	c->nodelist.push_back(d);
	root->nodelist.push_back(a);
	root->nodelist.push_back(b);
	root->nodelist.push_back(c);
	
	node *e = new node;
	e->val = 5;
	node *f = new node;
	f->val = 6;
	a->nodelist.push_back(e);
	a->nodelist.push_back(f);

	node *g = new node;
	g->val = 7;
	d->nodelist.push_back(g);
	
	return root;
}
bnode *makebtree()
{
	bnode *root = new bnode;
	root->val = 0;
	
	bnode *a = new bnode;
	a->val = 1;
	bnode *b = new bnode;
	b->val = 2;
	
	bnode *c = new bnode;
	c->val = 3;
	bnode *d = new bnode;
	d->val = 4;
	bnode *e = new bnode;
	e->val = 5;
	bnode *f = new bnode;
	f->val = 6;
		
	root->left = a;
	root->right = b;
	
	a->left = c;
	a->right = d;
	
	b->left = e;
	b->right = f;

	return root;
}
void preorder(bnode *root)
{
	if(root != NULL)
	{
		std::cout<<root->val;
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(bnode *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		std::cout<<root->val;
	}
}
void inorder(bnode *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		std::cout<<root->val;
		inorder(root->right);
	}
}
void bfs(node *root, int size)
{
	std::queue<node*> q;
	std::vector<int> parent, distance;
	
	for(int i = 0; i<size; i++)
	{
		parent.push_back(-1);
		distance.push_back(-1);
	}	
	parent[0] = 0;
	distance[0] = 0;

	q.push(root);
	while(!q.empty())
	{
		node *cur = q.front();
		q.pop();
		std::cout<<cur->val<<std::endl;
		for(int i = 0; i<cur->nodelist.size(); i++)
		{
			node *n = cur->nodelist[i];
			if(distance[n->val] == -1)
			{
				distance[n->val] = distance[cur->val] + 1;
				parent[n->val] = cur->val;
				q.push(n);
			}
		}
	}
}
void dfs(node *root, int size)
{
	std::stack<node*> s;
	std::vector<int> parent, distance;
	for(int i = 0; i<size; i++)
	{
		distance.push_back(-1);
		parent.push_back(-1);
	}
	distance[0] = 0;
	parent[0] = 0;
	
	s.push(root);
	while(!s.empty())
	{
		node *cur = s.top();
		s.pop();
		std::cout<<cur->val<<std::endl;
		for(int i = 0; i<cur->nodelist.size(); i++)
		{
			node *n = cur->nodelist[i];
			if(distance[n->val] == -1)
			{
				parent[n->val] = cur->val;
				distance[n->val] = distance[cur->val] + 1;
				s.push(n);
			}
		}
	}
}
int main()
{
	node* root = maketree();
	bnode* broot = makebtree();
	std::cout<<"inorder:   ";
	inorder(broot);
	std::cout<<std::endl;
	
	std::cout<<"preorder:  ";
	preorder(broot);
	std::cout<<std::endl;

	std::cout<<"postorder: ";
	postorder(broot);
	std::cout<<std::endl;
	
	std::cout<<"BFS: "<<std::endl;
	bfs(root, 8);
	std::cout<<"DFS: "<<std::endl;
	dfs(root, 8);
}
