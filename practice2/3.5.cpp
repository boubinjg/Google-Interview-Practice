#include<iostream>
#include<stack>
//sort a stack using only a temp stack
void sortStack(std::stack<int>& s)
{
	std::stack<int> temp;
	int i = 1;
	while(i < s.size())
	{
		//push the top i values onto s
		for(int j = 0; j<i; j++)
		{
			int t = s.top();
			s.pop();
			temp.push(t);
		}
		
		int piv = s.top();
		s.pop();
		bool pivPlaced = false;
		
		while(!temp.empty())
		{
			if(temp.top() < piv && !pivPlaced)
			{
				s.push(piv);
				pivPlaced =true;
			}
			s.push(temp.top());
			temp.pop();	
		}
		if(!pivPlaced)
			s.push(piv);
		i++;
	}
}
int main()
{
	std::stack<int> s;
	s.push(10);
	s.push(6);
	s.push(5);
	s.push(8);

	sortStack(s);

	while(!s.empty())
	{
		std::cout<<s.top()<<std::endl;
		s.pop();
	}

	return 0;
}
