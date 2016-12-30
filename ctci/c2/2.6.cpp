#include <iostream>
struct node{
	node *next;
	node *prev;
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
bool checkPal(node *head)
{
	node *runner = head;
	while(runner->next != NULL)
	{
		runner = runner->next;
	}	
	while(runner->prev != head->next && head->next != runner)
	{
		if(runner->val != head->val)
			return false;
	}
	return true;
}
int main()
{
	node *head = new node;
	head->val = 0;
	head->next = NULL;
	head->prev = NULL;
	node *cur = head;
	for(int i = 1; i<2; i++)
	{
		node *n = new node;
		n->prev = cur;
		n->next = NULL;
		n->val = 0;
		cur->next = n;
		cur = n;
	}
	print(head);
	
	std::cout<<checkPal(head);
	return 0;
}
