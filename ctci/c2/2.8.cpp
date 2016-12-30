#include <iostream>
#include <unordered_map>
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
node* cycle(node* head)
{
	std::unordered_map<node*, bool> um;
	while(head != NULL)
	{
		if(um[head])
			return head;
		um[head] = true;
		head = head->next;
	}
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
	head->next = head;
	node *n = cycle(head);
	std::cout<<n->val<<std::endl;
	return 0;
}
