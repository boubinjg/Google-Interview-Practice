//program to sort a stack such that the smalest items are on the top. you can use
//an additional temporary stack, but you may not copy the elements into any other data structure.
#include<stack>
#include<limits.h>
#include<iostream>
void printStack(std::stack<int> s)
{
	std::cout<<std::endl;
	while(!s.empty())
	{
		std::cout<<s.top()<<" ";
		s.pop();
	}
	std::cout<<std::endl;
}
void sortStack(std::stack<int> s)
{
	std::stack<int> r;
	printStack(s);
	while(!s.empty())
	{
		int temp = s.top();
		s.pop();
		while(!r.empty() && r.top() > temp)
		{
			s.push(r.top());
			r.pop();
		}
		r.push(temp);
	}
	while(!r.empty())
	{	
		s.push(r.top());
		r.pop();
	}
	printStack(r);
}
int main()
{
	std::stack<int> s;
	s.push(5);
	s.push(6);
	s.push(8);
	s.push(2);
	sortStack(s);
}
