#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
struct node{
	node *next;
	int val;
};
int kthToLastTime(int k, node *root)
{
	std::vector<int> v;
	int size = 0;
	while(root != NULL)
	{
		v.push_back(root->val);
		root = root->next;
		size++;
	}
	return v[size-1-k];
}
int kthToLastSpace(int k, node *root)
{
	std::vector<int> v;
	int size = 0;
	node *sto = root;
	while(root != NULL)
	{
		v.push_back(root->val);
		root = root->next;
		size++;
	}
	int count = 0;
	while(count < size-k-1)
	{
		sto = sto->next;
		count++;
	}
	return sto->val;
}
int main()
{
	node *head = new node;
	head->next = NULL;
	head->val = 1;
	for(int i = 2; i<=5; i++)
	{		
		node *n = new node;
		n->next = head;
		n->val = i;
		head = n;
	}
	std::cout<<kthToLastTime(2, head)<<std::endl;
	std::cout<<kthToLastSpace(2, head)<<std::endl;
}
