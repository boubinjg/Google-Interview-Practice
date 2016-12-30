#include <algorithm>
#include <iostream>
#include <vector>
int partition(std::vector<int>& vec, int left, int right)
{
	//set the pivot to the value at the far left
	int pivotVal = vec[left];
	int pivot = left;
	int j;
	
	for(j = pivot+1; j<right; j++)
	{
		if(vec[j] <= pivotVal)
		{
			pivot++;
			std::swap(vec[pivot],vec[j]);
		}
	}
	std::swap(vec[pivot], vec[left]);
	return pivot;
}
void quicksort(std::vector<int>& vec, int left, int right)
{
	int pivot;
	//base case (if left < right, that means the subset being sorted is of size 0 or less)
	if(left < right)
	{
		//partition the array and return the pivot
		pivot = partition(vec, left, right);
		//sort from the left side to the pivot
		quicksort(vec, left, pivot);
		//sort from the right side to the pivot
		quicksort(vec, pivot+1, right);
	}	
}
int main()
{
	std::vector<int> v;
	v.push_back(56);
	v.push_back(100);
	v.push_back(10);
	v.push_back(50);
	v.push_back(1000);
	v.push_back(1);
	v.push_back(55);
	quicksort(v, 0, v.size());
	
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<std::endl;
}
