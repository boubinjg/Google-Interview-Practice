#include<iostream>
template <class T>
struct node{
	node* next;
	node* last;
	T val;
};
template <class T>
class circularArr{
private:
	node<T>* head;
	int size;
public:
	circularArr()
	{
		head = new node<T>;
		head->next = head;
		head->last = head;
		size = 0;
	}
	void add(T item)
	{
		if(size = 0)
			head->val = item;
		else
		{
			node<T>* n = new node<T>;
			n->val = item;
			n->last = head->last;
			n->next = head;
			head->last->next = n;
			head->last = n;
		}
		size++;
	}
	T get(int pos)
	{
		node<T>* cur = head;
		//if(pos >= size)
		//	return -1;
		for(int i = 0; i<=pos; i++)
			cur = cur->next;
		
		return cur->val;
	}
	void rotate(int dist)
	{
		while(dist > 0)
		{
			head = head->next;
			dist--;
		}
	}
};
int main()
{
	circularArr<int> c;
	c.add(0);
	c.add(1);
	c.add(2);
	c.add(3);
	c.add(4);
	c.add(5);
	std::cout<<c.get(0)<<" "<<c.get(5)<<std::endl;
	c.rotate(3);
	std::cout<<c.get(0)<<std::endl;

}

