#include<iostream>
int trailingZeros(int fact)
{
	int res = 1;
	int tZeros = 0;
	for(int i = 1; i<=fact; i++)
	{
		res *= i;	
		while(res%10 == 0)
		{
			res /= 10;
			tZeros++;
		}
		res = res%10;	
		std::cout<<res<<std::endl;
	}
	return tZeros;
}
int main()
{
	std::cout<<trailingZeros(52)<<std::endl;
}
