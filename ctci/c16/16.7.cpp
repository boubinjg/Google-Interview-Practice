#include<iostream>
#include<algorithm>
#include<limits.h>
int findMaxBitShift(int one, int two)
{

}
int findMax(int one, int two)
{
	int i = one - two;
	i = (i^-1)+1;
	one += i;
	two += i;
	return (one+two - i)/2;
}
int main()
{
	std::cout<<findMax(-100, 10)<<std::endl;
}
