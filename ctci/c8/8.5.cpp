#include<iostream>
#include<vector>
int multiply(int i, int j)
{
	if(i == 0)
		return 0;
	else
		return j + multiply(i-1, j);
}
int main()
{
	std::cout<<multiply(5,10)<<std::endl;
}
