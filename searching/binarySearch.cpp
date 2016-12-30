#include<iostream>
#include<algorithm>
#include<vector>
int binarySearch(std::vector<int> arr, int value, int left, int right)
{
	while(left <= right)
	{
		int middle = (left+right)/2;
		if(arr[middle] == value)
			return middle;
		else if(arr[middle] > value)
			right = middle-1;
		else
			left = middle+1;
	}
	return -1;
}
int main()
{
	std::vector<int> v;
	for(int i = 0; i<=100; i++)
		v.push_back(i);
	std::cout<<binarySearch(v, 10, 0, 100)<<std::endl;
	std::cout<<binarySearch(v, 30, 0, 100)<<std::endl;
	std::cout<<binarySearch(v, 101, 0, 100)<<std::endl;
}
