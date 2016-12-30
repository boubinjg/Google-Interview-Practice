#include<iostream>
#include<vector>
#include<limits.h>
int maxSum(std::vector<int> v, int pos)
{
	int ret = v[pos],cur;
	for(int i = pos; i<v.size(); i++)
	{
		for(int j = i+2; j<v.size(); j++)
		{
			cur =v[i]+maxSum(v, j);
			if(cur > ret)
				ret = cur;
		}
	}
	return ret;
}
int main()
{
	std::vector<int> v;
	for(int i = 0; i<10; i++)
	{
		v.push_back(i);
		if(i%2)
			v[i]*=-1;
	}
	v.push_back(10);
	v.push_back(5);
	
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;

	std::cout<<maxSum(v, 0)<<std::endl;
}
