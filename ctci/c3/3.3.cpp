#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>

template <class T>
class StackOfStacks{
private:
	std::vector<std::stack<T> > stacks;
	int threshold;
public:
	StackOfStacks(int threshold)
	{
		this->threshold = threshold;
		std::stack<T> s;
		stacks.push_back(s);
	}
	void push(T val)
	{
		if(stacks.back().size() > threshold)
		{
			std::stack<T> s;
			s.push(val);
			stacks.push_back(s);
		}
		else
		{
			stacks.back().push(val);
		}
	}
	void pop()
	{
		stacks.back().pop();
		if(stacks.back().size() == 0)
		{
			stacks.pop_back();
		}
		
	}
	T peek()
	{
		return stacks.back().top();
	}
};

int main()
{
	StackOfStacks<char> s('2');
	s.push('1');
	s.push('2');
	s.push('3');
	s.push('4');
	std::cout<<"peek ";
	std::cout<<s.peek();
	for(int i = 0; i<4; i++)
	{
		std::cout<<s.peek()<<std::endl;
		s.pop();
	}
}
