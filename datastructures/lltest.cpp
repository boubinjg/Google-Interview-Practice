#include <iostream>
class LinkedList
{
	struct node
	{
		node* next;
		int val;	
	};
	private:
		node *head = NULL;
	public:
		LinkedList()
		{

		}
		void add(int value)
		{
			node *n = new node;
			n ->next = head;
			n ->val = value;	
			head = n;
		}
		int pop()
		{
			int ret = head->val;
			node *n = head->next;
			delete head;
			head = n;
			return ret;
		}
		void traverse()
		{
			node *cur = head;
			while(cur != NULL)
			{
				std::cout<<cur->val<<" ";
				cur = cur->next;
			}
			std::cout<<std::endl;
		}
		void reverse()
		{
			node *cur = head, *prev = NULL, *next = NULL;
			while(cur != NULL)
			{
				next = cur->next;
				cur->next = prev;
				prev = cur;
				cur = next;
			}
			head = prev;
		}
		~LinkedList()
		{
			node *cur = head;
			while(cur != NULL)	
			{
				node *n = new node;
				n = cur->next;
				delete cur;
				cur = n;
			}
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
	std::cout<<list.pop()<<std::endl;
}

