#include<iostream>
#include<vector>
#include<algorithm>
void printVec(std::vector<int> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
}
void peakValley(std::vector<int> v)
{
	std::vector<int>::iterator middle = v.begin() + v.size()/2;
	std::vector<int> left(v.begin(), middle);
	std::vector<int> right(middle, v.end());
	std::vector<int> ret;
	
	while(left.size() > 0 && right.size() > 0)
	{
		
		ret.push_back(right[0]);
		right.erase(right.begin());
		ret.push_back(left[0]);
		left.erase(left.begin());
	}
	while(left.size() > 0)
	{
		ret.push_back(left[0]);
		left.erase(left.begin());
	}
	while(right.size() > 0)
	{
		ret.push_back(right[0]);
		left.erase(right.begin());
	}
	printVec(ret);
}
int main()
{
	std::vector<int> v;
	for(int i = 0; i<20; i++)
	{
		v.push_back(i);
	}
	peakValley(v);
}
