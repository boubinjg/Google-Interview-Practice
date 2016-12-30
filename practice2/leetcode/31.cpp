#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
void printVec(std::vector<int> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
}
void nextPermutation(std::vector<int>& v)
{
	int last = INT_MIN;
	int sortSize = 0;
	std::vector<int> sortStore;
	
	for(auto it = v.rbegin(); it<v.rend(); it++)
	{
		if(last <= *it)
		{
			sortSize++;
			last = *it;
			sortStore.push_back(*it);
		}
		else
		{
			last = INT_MAX;
		}
	}
	
	if(sortSize == v.size())
		std::sort(v.begin(), v.end());
	else
	{
		int lastIndex = v.size()-sortSize-1;
		int nextVal = 0;
		for(auto it = sortStore.begin(); it<sortStore.end(); it++)
		{
			if(*it > v[lastIndex]) 
			{
				nextVal = *it;
				*it = v[lastIndex];
				break;
			}
		}
		v[lastIndex] = nextVal;
		for(int i = lastIndex+1; i<v.size(); i++)
		{
			v[i] = sortStore[i-lastIndex-1];
		}	
	}
}
int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(1);
	//v.push_back(1);
	//v.push_back(1);
	nextPermutation(v);
}
