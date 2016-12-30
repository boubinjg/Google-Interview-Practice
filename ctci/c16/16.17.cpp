#include<vector>
#include<iostream>
#include<limits.h>
void printVec(std::vector<int> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<std::endl;
}
int sum(std::vector<int> v)
{
	int sum = 0;
	for(int n : v)
		sum+= n;
	return sum;
}
std::vector<int> findMax(int p, std::vector<int> v)
{
	int max = v[p];
	int cur = max;
	std::vector<int> ret;
	std::vector<int> cv;
	for(int i = p+1; i<v.size(); i++)
	{
		cur+=v[i];
		cv.push_back(v[i]);
		if(cur > max)
		{
			max = cur;
			ret = cv;
		}
	}
	return cv;
}
std::vector<int> findHighestContig(std::vector<int> v)
{
	int max = INT_MIN;
	std::vector<int> ret;
	std::vector<int> cur;
	for(int i = 0; i<v.size(); i++)
	{
		cur = findMax(i, v);
		if(max < sum(cur))
		{
			max = sum(cur);
			ret = cur;
		}
	}
	printVec(ret);
	return ret;
}
int main()
{
	std::vector<int> v;
	for(int i = 1; i<=10; i++)
	{
		if(i%2)
			v.push_back(i);
		else
			v.push_back(-i);
	}
	v.push_back(11);
	v.push_back(-1);
	v.push_back(12);	
	//printVec(v);
	findHighestContig(v);
	return 0;
}
