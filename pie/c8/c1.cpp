#include<iostream>
#include<vector>
#include<limits.h>
void selectionSort(std::vector<int>& v)
{
	for(auto iti = v.begin(); iti<v.end(); iti++)
	{	
		int min = INT_MAX;
		auto minPos = iti;
		for(auto itj = iti; itj<v.end(); itj++)
		{
			if(*iti > *itj)
			{
				min = *itj;
				minPos = itj;
			}
		}
		std::swap(iti, minPos);
	}
}
int main()
{
	std::vector<int> v;
	for(int i = 10; i>0; i--)
		v.push_back(i);

	selectionSort(v);
	for(auto it = v.begin(); it<v.end(); it++)
		std::cout<<*it<<std::endl;
}
