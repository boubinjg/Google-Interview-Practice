#include<iostream>
#include<vector>
int findMagic(int a[], int start, int end)
{

	int middle = (start+end)/2;
	if(end <= start)
		return -1;
	if(middle == a[middle])
		return middle;
	else if(middle[a] > middle)
	{
		return findMagic(a, start, middle-1);
	}
	else
		return findMagic(a, middle+1, end);
}
int main()
{
	int a[10] = {1,1,1,1,7,8,9,10,11,20};
	std::cout<<findMagic(a, 0, 9)<<std::endl;;
}
