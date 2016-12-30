#include <vector>
#include <iostream>
#include <algorithm>
template <class T>
class Stack{
	private:
		std::vector<T> stack;
		T min;
	public:
		Stack()
		{	
				
		}
		void push(T next)
		{
			if(stack.size() == 0)
				min = next;
			else
			{
				min = std::min(next, min);
			}
			stack.push_back(next);
		}
		void pop()
		{
			if(stack.size() > 0)
				stack.pop_back();
			min = *std::min_element(stack.begin(), stack.end());
		}
		T peek()
		{
			if(stack.size() > 0)
				return stack.back();
		}
		T stackMin()
		{
			return min;
		}
};

int main()
{
	return 0;
}
