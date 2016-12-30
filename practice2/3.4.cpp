#include<iostream>
#include<stack>
template <class T> 
class myQueue
{
private:
	std::stack<T> mainStack;
	std::stack<T> tempStack;
public:	
	void push(T item)
	{
		mainStack.push(item);
	}
	T peek()
	{
		T ret;
		while(!mainStack.empty())
		{
			T item = mainStack.top();
			mainStack.pop();
			tempStack.push(item);
		}
		ret = tempStack.top();
		while(!tempStack.empty())
		{
			T item = tempStack.top();
			tempStack.pop();
			mainStack.push(item);
		}
		return ret;
	}
	void pop()
	{
		while(!mainStack.empty())
		{
			T item = mainStack.top();
			mainStack.pop();
			tempStack.push(item);
		}
		tempStack.pop();
		while(!tempStack.empty())
		{
			T item = tempStack.top();
			tempStack.pop();
			mainStack.push(item);
		}
		
	}
};
int main()
{
	myQueue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	std::cout<<q.peek()<<std::endl;
	q.pop();
	q.pop();
	std::cout<<q.peek()<<std::endl;
	return 0;
}
