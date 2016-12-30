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

void inorder(bnode *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		std::cout<<root->val<<" ";
		inorder(root->right);
	}
}
void preorder(bnode *root)
{
	if(root != NULL)
	{
		std::cout<<root->val<<" ";
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
		std::cout<<root->val<<" ";
	}
}
void visit(node *n)
{
	std::cout<<n->val<<" ";
}
void bfs(node *root, int size)
{
	std::cout<<"Breadth first traversal: ";
	std::queue<node*> q;
	std::vector<int> parent;
	std::vector<int> distance;

	for(int i = 0; i<size; i++)
	{
		distance.push_back(-1);
		parent.push_back(-1);
	}
	q.push(root);
	distance[0] = 0;
	parent[0] = 0;
	
	std::cout<<"0 ";
	while(!q.empty())
	{
		node *current = q.front();
		q.pop();
		for(int i = 0; i<current->nodelist.size(); i++)
		{
			node *n = current->nodelist[i];
			if(distance[n->val] == -1)
			{
				distance[n->val] = distance[current->val]+1;
				parent[n->val] = current->val;
				q.push(n);
				std::cout<<n->val<<" ";
			}
		}
	}
	std::cout<<std::endl;
	for(int i = 0; i<size; i++)
	{
		std::cout<<i<<" "<<parent[i]<<" "<<distance[i]<<std::endl;
	}
}
void dfs(node *root, int size)
{
	std::cout<<"Depth first traversal: ";
	std::stack<node*> s;
	std::vector<int> parent;
	std::vector<int> distance;

	for(int i = 0; i<size; i++)
	{
		distance.push_back(-1);
		parent.push_back(-1);
	}
	s.push(root);
	distance[0] = 0;
	parent[0] = 0;
	
	std::cout<<"0 ";
	while(!s.empty())
	{
		node *current = s.top();
		s.pop();
		for(int i = 0; i<current->nodelist.size(); i++)
		{
			node *n = current->nodelist[i];
			if(distance[n->val] == -1)
			{
				distance[n->val] = distance[current->val]+1;
				parent[n->val] = current->val;
				s.push(n);
				std::cout<<n->val<<" ";
			}
		}
	}
	std::cout<<std::endl;
	for(int i = 0; i<size; i++)
	{
		std::cout<<i<<" "<<parent[i]<<" "<<distance[i]<<std::endl;
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

	std::cout<<root->nodelist[0]->nodelist[0]->val<<std::endl;
}
