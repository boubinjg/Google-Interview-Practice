#include<iostream>
struct node{
	node* next;
	int val;
};
int nthToLast(node* root, int n)
{
	node* cur = root;
	int length = 0;
	while(cur != NULL)	
	{
		length++;
		cur = cur->next;
	}
	int count = 0;
	cur = root;
	while(count < length-n-1)
	{
		cur = cur->next;
		count++;
	}
	return cur->val;
}
int main()
{
	node* one = new node;
	node* two = new node;
	node* three = new node;
	one->val = 1;
	two->val = 2;
	three->val = 3;
	one->next = two;
	two->next = three;
	std::cout<<nthToLast(one, 1)<<" "<<nthToLast(one, 0)<<std::endl;
}
