#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right)
{
	std::vector<int> result;
	unsigned leftCount = 0, rightCount = 0;
	
	while(leftCount < left.size() && rightCount < right.size())
	{
		if(left[leftCount] < right[rightCount])
		{
			result.push_back(left[leftCount]);
			leftCount++;
		}
		else
		{ 
			result.push_back(right[rightCount]);
			rightCount++;
		}
	}
	while(rightCount < right.size())
	{
		result.push_back(right[rightCount]);
		rightCount++;
	}	
	while(leftCount < left.size())
	{
		result.push_back(left[leftCount]);
		leftCount++;
	}
	return result;
}
std::vector<int> mergeSort(std::vector<int> vec)
{
	//base case, if size is 1, vector is sorted
	if(vec.size() == 1)
		return vec;
	
	//find the middle of the vector
	std::vector<int>::iterator middle = vec.begin() + (vec.size()/2);
	
	//split the vector in two
	std::vector<int> left(vec.begin(),middle);
	std::vector<int> right(middle, vec.end());
	
	//sort the left size
	left = mergeSort(left);
	//sort the right side
	right = mergeSort(right);
	//merge the left and right, returning a sorted vector
	return merge(left,right);
	
}
int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(-1);
	v.push_back(0);
	v.push_back(100);
	v.push_back(-100);

	v = mergeSort(v);
	for(int i = 0; i<v.size(); i++)
	{
		std::cout<<v[i]<<std::endl;
	}
}
