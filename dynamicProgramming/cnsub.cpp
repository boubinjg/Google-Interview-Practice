#include<vector>
#include<iostream>
#include<limits.h>
std::vector<int> memo;
int longestSubNseq(std::vector<int> v, int index, int prev)
{
	if(memo[index] != -1)
		return memo[index];
	else
	{
		if(v[index] > prev)
		{
			int ret = 0, max = 0;
			for(int i = index+1; i<v.size(); i++)
			{
				ret = 1 + longestSubNseq(v, i, v[index]);
				if(ret > max)
					max = ret;
			}
			memo[index] = max;
			return max;
		}
		else
			return 0;
	}
}
int lsn(std::vector<int> v)
{
	int max = 0;
	std::cout<<std::endl;
	for(int i = 0; i<v.size(); i++)
	{
		int cur = 1 + longestSubNseq(v, i, INT_MIN);
		if(cur > max)
			max = cur;
	}
	return max;
}
int main()
{
	std::vector<int> v;
	v.push_back(100);
	v.push_back(102);
	v.push_back(103);
	memo.push_back(-1);
	memo.push_back(-1);
	memo.push_back(-1);
	
	for(int i = 0; i<10; i++)
	{
		v.push_back(i);	
		memo.push_back(-1);
		if(i == 5)
		{
			v.push_back(-1);
			memo.push_back(-1);
		}
	}
	v.push_back(10000000);
	memo.push_back(-1);
	
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
	int j = lsn(v);
	std::cout<<j<<std::endl;
}
