#include<iostream>
#include<limits.h>
void sortp(int* a, int size)
{
	for(int i = 0; i<size; i++)
	{
		int min = INT_MAX;
		int minIndex = size;
		for(int j = i; j<size; j++)
		{
			if(a[j] <= min)
			{
				min = a[j];	
				minIndex = j;
			}
		}
		a[minIndex] = a[i];
		a[i] = min;
	}
}
int main()
{
	int *a = new int[4];
	for(int i = 0; i<4; i++)
	{
		a[i] = 10-i;
	}
	sortp(a,4);
	for(int i = 0; i<4; i++)
		std::cout<<a[i]<<std::endl;
}
