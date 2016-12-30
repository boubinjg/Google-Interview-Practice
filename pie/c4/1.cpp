#include<iostream>
struct node{
	node* next;
	int val;
};

class stack{
private:
	node* head;
public:
	stack()
	{
		head = NULL;
	}
	void push(int i)
	{
		node* n = new node;
		n->val = i;
		n->next = head;
		head = n;
	}
	void pop()
	{
		node* next = head->next;
		delete head;
		head = next;
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
};
int main()
{
	stack s;
	s.push(5);
	s.push(6);
	s.push(7);
	std::cout<<s.top()<<std::endl;
	s.pop();
	std::cout<<s.top()<<" "<<s.size()<<std::endl;
}
