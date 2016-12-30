#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
void print(std::vector<int> i)
{
	for(auto it = i.begin(); it<i.end(); it++)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
}
std::vector<int> merge(std::vector<int> i, std::vector<int> j)
{
	std::sort(i.begin(), i.end());
	std::sort(j.begin(), j.end());
	auto iit = i.begin();
	auto jit = j.begin();
	std::vector<int> result;
	while(iit != i.end() && jit != j.end())
	{
		if(*iit > *jit)
		{
			result.push_back(*jit);
			jit++;	
		}
		else
		{
			result.push_back(*iit);
			iit++;
		}
	}
	while(iit != i.end())
	{
		result.push_back(*iit);
		iit++;
	}
	while(jit != j.end())
	{
		result.push_back(*jit);
		jit++;
	}
	return result;
}
void findLowestPair(std::vector<int> i, std::vector<int> j)
{
	std::vector<int> r = merge(i, j);
	int min = 0;
	int minVal = INT_MAX;
	for(int i = 1; i<r.size(); i++)
	{
		if(r[i]-r[i-1] < minVal)
		{
			minVal = r[i]-r[i-1];
			min = i;
		}
	}
	print(r);
	std::cout<<r[min]<<" "<<r[min-1]<<std::endl;
}
int main()
{
	std::vector<int> j;
	std::vector<int> k;
	for(int i = 1; i<9; i++)
	{
		j.push_back((i*7)%51);
		k.push_back((i*11)%91);
	}
	print(j);
	print(k);
	findLowestPair(j, k);
}
