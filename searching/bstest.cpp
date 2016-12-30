#include<iostream>
#include<algorithm>
#include<vector>
int binarySearch(std::vector<int> vec, int val)
{
	int left = 0, right = vec.size();
	while(left <= right)
	{
		int middle = (left+right)/2;
		if(vec[middle] == val)
			return middle;
		else if(vec[middle] > val)
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
	std::cout<<binarySearch(v, 10)<<std::endl;
	std::cout<<binarySearch(v, 30)<<std::endl;
	std::cout<<binarySearch(v, 101)<<std::endl;
}
