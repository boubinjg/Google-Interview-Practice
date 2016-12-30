#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
struct node{
	node *next;
	int val;
};
void traverse( node *root)
{
	while(root != NULL)
	{
		std::cout<<root->val<<" ";
		root = root->next;
	}
	std::cout<<std::endl;
}
void remove(node *last, node *cur)
{
	if(cur->next = NULL)
		last ->next = NULL;
	else
		last ->next = cur->next;
	delete cur;
}
void removeDupesBetter(node *root)
{
	std::unordered_map<int,bool> um;
	node *last = NULL;
	while(root != NULL)
	{
		int val = root->val;
		if(um[root->val])
		{
			remove(root, last);
		}
		else
			um[root->val] = true;
		last = root;
		root = root->next;
	}
}
void removeDupes(node *root)
{
	std::vector<int> v;
	node *last = NULL;
	while(root != NULL)
	{
		int val = root->val;
		if(std::find(v.begin(), v.end(), val) != v.end())
		{
			remove(root, last);
		}
		else
			v.push_back(root->val);
		last = root;
		root = root->next;
	}
}

int main()
{
	node *head = new node;
	head->val = 1;
	head->next = NULL;
	
	node *cur = head;
	for(int i = 0; i<10; i++)
	{
		node *newnode = new node; 
		newnode ->next = cur;
		newnode ->val = i%3;
		cur = newnode;
	}
	head = cur;
	traverse(head);
	removeDupesBetter(head);
	traverse(head);
}
