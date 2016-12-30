#include <iostream>
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
void partition(int pivot, node *root)
{
	node *sto = root;
	node *smaller = NULL, *larger = NULL;
	node *smallerf = NULL;
	while(sto != NULL)
	{
		node *n = new node;
		n->val = sto->val;
		if(n->val > pivot)
		{
			if(larger == NULL)
			{	
				larger = n;
				larger->next = NULL;
			}
			else
			{
				n->next = larger;
				larger = n;
			}
		}
		else
		{
			if(smaller == NULL)
			{
				smaller = n;
				smaller ->next = NULL;
				smallerf = n;
			}
			else
			{
				n->next = smaller;	
				smaller = n; 
			}
		}
		sto = sto->next;
	}
	smallerf->next = larger;
	root->val = smaller->val;
	root->next = smaller->next;
}
int main()
{
	node *head = new node;
	head->val = 0;
	head->next = NULL;
	for(int i = 1; i<10; i++)
	{
		node *n = new node;
		n->next = head;
		n->val = i%5;
		head = n;
	}
	print(head);
	partition(2, head);
	print(head);
	return 0;
}
