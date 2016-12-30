#include<iostream>
#include<algorithm>
#include<vector>
int partition(std::vector<int>& vec, int left, int right)
{
	int pivot = left;
	int pivotVal = vec[left];
	for(int j = pivot+1; j<right; j++)
	{
		if(pivotVal > vec[j])
		{
			pivot++;
			std::swap(vec[j], vec[pivot]);
		}
	}
	std::swap(vec[left], vec[pivot]);
 	return pivot;
}
void quicksort(std::vector<int>& vec, int left, int right)
{
	if(left < right)
	{
		int pivot = partition(vec, left, right);
		quicksort(vec, left, pivot);
		quicksort(vec, pivot+1, right);
	}
}
int main()
{
	std::vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(8);
	v.push_back(6);
	v.push_back(4);
	v.push_back(3);
	quicksort(v, 0, v.size());
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<std::endl;
}
