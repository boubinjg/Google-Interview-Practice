#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> result;
	int lcount = 0, rcount = 0;
	while(lcount < left.size() && rcount < right.size())
	{
		if(left[lcount] < right[rcount])
		{
			result.push_back(left[lcount]);
			lcount++;
		}
		else
		{
			result.push_back(right[rcount]);
			rcount++;
		}
	}
	while(lcount < left.size())
	{
		result.push_back(left[lcount]);
		lcount++;
	}
	while(rcount < right.size())
	{
		result.push_back(right[rcount]);
		rcount++;
	}
	return result;
}
std::vector<int> mergesort(std::vector<int> vec)
{
	if(vec.size() == 1)
		return vec;
	std::vector<int>::iterator middle = vec.begin() +(vec.size()/2);
	
	std::vector<int> left(vec.begin(), middle);
	std::vector<int> right(middle, vec.end());
	
	left = mergesort(left);
	right = mergesort(right);
	
	return merge(left, right);
	
}
int main()
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(-1);
	v.push_back(100);
	v = mergesort(v);	
	for(int i = 0; i<v.size(); i++)
	{
		std::cout<<v[i]<<std::endl;
	}
}
