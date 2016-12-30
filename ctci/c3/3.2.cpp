#include <vector>
#include <iostream>
#include <algorithm>
struct stackNode{
	int val;
	int lastmin;
};
class Stack{
	private:
		std::vector<stackNode> stack;
		int min;
	public:
		Stack()
		{	
				
		}
		void push(int next)
		{
			stackNode n;
			n.val = next;
			n.lastmin = min;
			if(stack.size() == 0)
				min = next;
			else
			{
				min = std::min(next, min);
			}
			stack.push_back(n);
		}
		void pop()
		{
			if(stack.size() > 0)
			{
				min = stack.back().lastmin;
				stack.pop_back();
			}
		}
		int peek()
		{
			if(stack.size() > 0)
				return stack.back().val;
		}
		int stackMin()
		{
			return min;
		}
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(-1);
	std::cout<<s.stackMin()<<std::endl;
	s.pop();
	std::cout<<s.stackMin()<<" "<<s.peek()<<std::endl;
	return 0;
}
