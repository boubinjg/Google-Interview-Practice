#include<iostream>
int bitManip(int i, int j, int m, int n)
{
	m = m << i;
	for(int x = i; x<=j; x++)
	{
		n = n & ~(1<<x);
	}
	
	return m ^ n;
}
int main()
{
	std::cout<<bitManip(2,6,19, 111111111)<<std::endl;
}
