#include<vector>
#include<iostream>
int binarySearch(std::vector<int> v, int front, int back, int val)
{
	if(back < front)
		return -1;
	int middle = (front+back)/2;
	if(v[middle] == val)
		return middle;
	else if(v[middle] > val)
		return binarySearch(v, front, middle-1, val);
	else
		return binarySearch(v, middle+1, back, val);
}
int main()
{
	std::vector<int> v;
	for(int i = 0; i<10; i++)
		v.push_back(i);
	std::cout<<binarySearch(v,0,10,7)<<std::endl;
}
