#include<iostream>
struct node{
	node* next;
	int val;
};

class stack{
private:
	node* head;
	node* tail;
public:
	stack()
	{
		head = NULL;
		tail = NULL;
	}
	node* push(int i)
	{
		node* n = new node;
		n->val = i;
		n->next = head;
		if(head = NULL)
			tail = n;
		head = n;
		return head;
	}
	bool del(node* n)
	{
		if(n == NULL)
		{
			if(tail == head)
			{
				tail = NULL;
				delete head;
				head = NULL;
			}
			else
			{
				node* next = head->next;
				delete head;
				head = next;
			}
		}
		else if(n == tail)
		{
			delete tail;
			tail = NULL;
		}
		else 
		{
			node* c = head;
			while(c!=NULL && c->next != n)
				c = c->next;
			if(c==NULL)
				return false;	
			node* next = n->next;
			delete n;
			c->next = next;
		}
		return true;
	}
	bool insertAfter(node* n, int data)
	{
		node* nw = new node;
		nw->val = data;
		if(n == NULL)
		{
			nw->next = head;
			head = nw;
		}
		else if(n == tail)
		{	
			tail->next = nw;
			tail = nw;
		}		
		else
		{
			node* cur = head;
			while(cur != NULL && cur!=n)
				cur = cur->next;
			if(cur == NULL)
			{
				delete nw;
				return false;
			}
			node* next = cur->next;
			nw->next = next;
			cur->next = nw;
		}
		return true;
	}
	int top()
	{
		return head->val;
	}
	int size()
	{
		node* n = head;
		int count = 0;
		while(n != NULL)
		{
			count++;
			n = n->next;	
		}
		return count;
	}
	void print()
	{
		node* cur = head;
		while(cur != NULL)
		{
			std::cout<<cur->val<<std::endl;
			cur = cur->next;
		}
	}
};
int main()
{
	stack s;
	node* c = s.push(5);
	node* b = s.push(6);
	node* a = s.push(7);
	node* f = new node;
	//std::cout<<c->val<<std::endl;
	s.del(b);
	s.del(f);
	s.insertAfter(NULL, 8);
	
	s.print();
	
}
