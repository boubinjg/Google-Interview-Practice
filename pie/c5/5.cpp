#include<iostream>
#include<stack>
struct node{
	node* left;
	node* right;
	int val;
};
struct shallowNode{
	node* n;
	int depth;
};
shallowNode* findNext(node* heap)
{

	if(heap->left == NULL && heap->right == NULL){
		shallowNode* n = new shallowNode;
		n->depth = 1;
		n->n = heap;
	}
	shallowNode *l, *r;
	if(heap->left != NULL)
		shallowNode* l = findNext(heap->left);
	if(heap->right != NULL)
		shallowNode* r = findNext(heap->right);
	if(r->depth < l->depth)
	{
		return r;
	}
	else
	{
		return l;
	}
}
void add(node* heap, int i)
{
	if(heap == NULL)
	{
		heap = new node;
		heap->val = i;
	}
	else
	{
		node* n = findNext(heap)->n;
		n->val = i;
	}
}
void preorderAdd(node* heap, node* root)
{
	if(root != NULL)
	{
		add(heap, root->val);
		preorderAdd(heap, root->left);
		preorderAdd(heap, root->right);
	}
}
void preorder(node* root)
{
	if(root != NULL)
	{
		std::cout<<root->val<<std::endl;
		preorder(root->left);
		preorder(root->right);
	}
}
void print(node* root)
{
	while(root != NULL)
	{
		std::cout<<root->val<<std::endl;
		root = root->left;
	}
}
node* heapify(node* root)
{
	static node* heap = new node();
	heap->val = -1;
	preorderAdd(heap, root);	
	return heap;
}
int main()
{
	node* root = new node;
	node* a = new node;
	node* b = new node;
	node* c = new node;
	node* d = new node;
	node* e = new node;

	root->val = 0;
	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 4;
	e->val = 5;

	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	c->right = e;
	
	node* heap = NULL;
	add(heap, 5);
	add(heap, 6);
	add(heap, 7);
	add(heap, 8);
	preorder(heap);
	return 0;
}
