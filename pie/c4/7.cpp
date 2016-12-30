#include<iostream>
struct node{
	node* next;
	node* nextList;
	int val;
};
void printList(node* root)
{
	node* cur = root;
	while(cur != NULL)
	{
		std::cout<<cur->val<<" ";
		cur = cur->next;
	}
	std::cout<<std::endl;
}
void printLarge(node* root)
{
	node* cur = root;
	while(cur != NULL)
	{
		printList(cur);
		cur = cur->nextList;
	}
}
node* flatten(node* root)
{
	node* cur = root;
	while(cur->nextList != NULL)
	{
		node* ncur = cur;
		while(ncur->next != NULL)
		{
			ncur = ncur->next;
		}
		ncur->next = cur->nextList;
		cur = cur->nextList;
		//cur->nextList == NULL;
	}
}
int main()
{
	node* one = new node;
	node* two = new node;
	node* three = new node;
	node* four = new node;
	node* five = new node;
	node* six = new node;
	node* seven = new node;
	node* eight = new node;
	
	one->val = 1;
	two->val = 2;
 	three->val = 3;	
	four->val = 4;
	five->val = 5;
	six->val = 6;
	seven->val = 7;
	eight->val = 8;

	one->next = two;
	two->next = three;
 	three->next = NULL;	
	four->next = five;
	five->next = six;
	six->next = NULL;
	seven->next = eight;
	eight->next = NULL;

	one->nextList = four;
	two->nextList = NULL;
 	three->nextList = NULL;	
	four->nextList = seven;
	five->nextList = NULL;
	six->nextList = NULL;
	seven->nextList = NULL;
	eight->nextList = NULL;

	printLarge(one);
	flatten(one);
	printList(one);
}
