#include<iostream>
#include<vector>
int part(std::vector<int>& v, int begin, int end)
{
	int pivot, pivotVal;
	pivot = begin;
	pivotVal = v[begin];

	for(int i = begin+1; i<end; i++)
	{
		if(v[i] < pivotVal)
		{	
			pivot++;
			std::swap(v[i], v[pivot]);
		}	
	}
	std::swap(v[begin], v[pivot]);
	return pivot;
}
void quicksort(std::vector<int>& v, int begin, int end)
{
	if(begin < end)
	{
		int pivot = part(v, begin, end);
		quicksort(v, begin, pivot);
		quicksort(v, pivot+1, end);
	}
}
int main()
{
	std::vector<int> v;
	for(int i = 10; i>0; i--)
		v.push_back(i);
	quicksort(v, 0, v.size());
	for(auto it = v.begin(); it<v.end(); it++)
		std::cout<<*it<<std::endl;
}
