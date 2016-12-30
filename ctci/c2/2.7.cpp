#include <iostream>
#include <unordered_map>
#include <algorithm>
struct node{
	node *next;
	int val;
};
void print(node *root)
{
	while(root != NULL)
	{
		std::cout<<root->val<<" ";
		root = root->next;
	}
	std::cout<<std::endl;
}
node* intersect(node *h1, node *h2)
{
	while(h1 != NULL)
	{
		node* runner = h2;
		while(runner != NULL)
		{
			if(runner == h1)
				return h1;
			runner = runner->next;
		}
		h1 = h1->next;
	}
}
node* betterIntersect(node *h1, node *h2)
{
	std::unordered_map<node*, bool> um;
	while(h1 != NULL)
	{
		um[h1] = true;
		h1 = h1->next;
	}
	while(h2 != NULL)
	{
		if(um[h2])
			return h2;
		um[h2] = true;
		h2 = h2->next;
	}
}
int main()
{
	node *head1 = new node;
	head1->val = 0;
	head1->next = NULL;
	for(int i = 1; i<10; i++)
	{
		node *n = new node;
		n->next = head1;
		n->val = i%5;
		head1 = n;
	}
	node *head2 = new node;
	head2 = head1;
	for(int i = 1; i<10; i++)
	{
		node *n = new node;
		n->next = head2;
		n->val = i%5;
		head2 = n;
	}
	
	
	print(head1);
	print(betterIntersect(head1, head2));
	return 0;
}
