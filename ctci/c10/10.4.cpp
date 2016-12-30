#include<iostream>
#include<vector>
bool heat = true;
int findVal(std::vector<int> listy, int index, int inc, int val)
{
	std::cout<<listy[index]<<std::endl;
	if(listy[index] == val)
		return index;
	else if(listy[index] < val && listy[index+1] > val)
		return -1;
	else if(listy[index] < val)
	{
		if(heat)
			inc*=2;
		else
			inc/=2;
		index += inc;
		return findVal(listy, index, inc, val); 
	}
	else
	{
		heat = false;
		inc /= 2;
		index -= inc;
		return findVal(listy, index, inc, val);
	}
}
int main()
{
	std::vector<int> v;
	for(int i = 0; i<1000; i++)
	{
		v.push_back(i*2);
	}
	std::cout<<findVal(v, 0, 1, 173);
}
