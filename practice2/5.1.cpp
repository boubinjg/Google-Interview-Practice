#include<iostream>
int insert(int m, int n, int i, int j)
{
	for(; i<j; i++)
	{
		int p = 1;
		p = p<<i;
		p = p&m;	
		n = n|p;
	}
	return n;
}
int main()
{
	int i = insert(100, 1048576, 0, 8);
	std::cout<<i<<std::endl;
	return 0;
}
