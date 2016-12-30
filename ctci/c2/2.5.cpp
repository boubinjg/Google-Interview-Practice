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
node* add(node *h1, node *h2)
{
	node* head = new node;
	node *headsto = head, *last = NULL;
	int carry = 0;
		
	while(h1 != NULL && h2 != NULL)
	{
		carry += h1->val + h2->val;
		head->val = carry%10;
		carry /= 10;
		node *n = new node;
		head->next = n;
		last = head;
		head = n;
		h1 = h1->next;
		h2 = h2->next;
	}
	while(h1 != NULL)
	{
		carry += h1->val;
		head->val = carry%10;
		carry /= 10;
		node *n = new node;
		head->next = n;
		last = head;
		head = n;
		h1 = h1->next;
	}
	while(h2 != NULL)
	{
		carry += h2->val;
		head->val = carry%10;
		carry /= 10;
		node *n = new node;
		head->next = n;
		last = head;
		head = n;
		h2 = h2->next;
	}
	last->next = NULL;
	delete(head);
	return headsto;
}
int main()
{
	node *head1 = new node;
	node *head2 = new node;
	head1->val = 1;
	head2->val = 1;
	head1->next = NULL;
	head2->next = NULL;
	for(int i = 1; i<10; i++)
	{
		node *n = new node;
		node *n2 = new node;
		n->next = head1;
		n->val = i%5+1;
		head1 = n;

		n2 ->next = head2;
		n2->val = i;
		head2 = n2;
	}
	print(head1);
	print(head2);
	node *addHead = add(head1, head2);
	print(addHead);
	return 0;
}
