#include <iostream>
struct node{
	node *next;
	int val;
};
void removeMiddle(node *n)
{
	node *next = n->next;
	
	n->val = next->val;
	n->next = next->next;
	delete next;
}
void print(node *root)
{
	while(root != NULL)
	{
		std::cout<<root->val<<" ";
		root = root->next;
	}
	std::cout<<std::endl;
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
		n->val = i;
		head = n;
	}
	print(head);
	removeMiddle(head->next->next->next);
	print(head);
	return 0;
}
