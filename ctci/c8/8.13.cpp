#include <iostream>
#include <vector>
#include <queue>
#include <stack>
struct box{
	int width, height, length;
};
int calcStack(std::queue<box> b, std::stack<box> boxStack)
{
	int ret, max = 0, size = b.size();

	box top = boxStack.top();
	
	if(size == 0)
		return 0;
	while(size > 0)
	{
		box cur = b.front();
		b.pop();
		ret = 0;
		if(cur.length <= top.length && cur.height <= top.height && cur.width <= top.width)
		{
			boxStack.push(cur);
			ret = 1 + calcStack(b, boxStack); 
			boxStack.pop();
		}
		if(ret > max)
			max = ret;
		b.push(cur);
		size--;
	}
	return max;
}
int largestStack(std::queue<box> b, std::stack<box> boxStack)
{
	int ret, max = 0, size = b.size();
	while(size > 0)
	{
		box cur = b.front();
		b.pop();
		boxStack.push(cur);
		ret = 1 + calcStack(b, boxStack);
		if(ret > max)
			max = ret;
		boxStack.pop();
		b.push(cur);
		size--;
	}
	return max;
}
int main()
{
	std::queue<box> boxes;
	std::stack<box> bStack;
	for(int i = 0; i<10; i++)
	{
		box b;
		b.height = i*5 % 40 + 1;
		b.width = i*4 % 30 + 1;
		b.length = i*3 % 20 + 1;
		boxes.push(b);
	}
	std::queue<box> bos = boxes;
	int size = bos.size();
	for(int i = 0; i<size; i++)
	{
		box bo = bos.front();
		bos.pop();
		std::cout<<bo.height<<" "<<bo.length<<" "<<bo.width<<std::endl;
	}
	std::cout<<"Start: "<<std::endl;
	std::cout<<largestStack(boxes, bStack)<<std::endl;
	return 0;
}
