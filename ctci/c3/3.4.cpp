#include <stack>
#include <iostream>
//make a queue using two stacks
template <class T>
class myQueue{
private:
	std::stack<T> s1;
	std::stack<T> s2;
public:
	myQueue()
	{
		
	}
	void enqueue(T next)
	{
		s1.push(next);
		std::stack<T> temp = s1;
		for(int i = 0; i<s2.size(); i++)
			s2.pop();
		for(int i = 0; i<s1.size(); i++)
		{
			s2.push(temp.top());
			temp.pop();
		}
	}
	T dequeue()
	{
		s2.pop();
		std::stack<T> temp = s2;
		for(int i = 0; i<s1.size(); i++)
			s1.pop();
		for(int i = 0; i<s2.size(); i++)
		{
			s1.push(temp.top());
			temp.pop();
		}
	}
	bool isEmpty()
	{
		return s1.isEmpty();
	}
	T peek()
	{
		return s2.top();
	}
};
int main()
{
	myQueue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	
	std::cout<<q.peek()<<std::endl;
	q.dequeue();
	std::cout<<q.peek()<<std::endl;
}
