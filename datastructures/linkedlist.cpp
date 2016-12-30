#include <iostream>

class LinkedList{
	struct node{
		int value;
		node *next;
	};
private: 
	node *head;
public:
	LinkedList() 
	{
		head = NULL;	
	}
	void add(int val)
	{
		node *n = new node();
		n->value = val;
		n->next = head;
	
		head = n;
	}
	int pop()
	{
		node *n = head;
		int ret = n->value;
		head = head->next;
		delete n;
		return ret;
	}
	void traverse()
	{
		node* t = head;
		while(t != NULL)
		{
			std::cout<<t->value<<std::endl;
			t = t->next;
		}
		
	}
	void reverse()
	{
		if(head == NULL) return;
		
		node *prev = NULL, *current = NULL, *next = NULL;
		current = head;
		while(current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	~LinkedList()
	{
		node *cur = head;
		while(cur != NULL)
		{
			node *next = cur->next;
			delete cur;
			cur = next;
		}
		delete head;
	}
};

int main()
{
	LinkedList list;
	list.add(5);
	list.add(10);
	list.add(50);

	list.traverse();
	list.reverse();
	list.traverse();
}

