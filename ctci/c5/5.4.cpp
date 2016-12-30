#include <iostream>
int countOnes(int n)
{
	int count = 0;
	for(int i = 0; i<32; i++)
	{
		count += (((1<<i) & n) != 0);
	}
	return count;
}
int smallAndLarge(int x)
{
	int ones = countOnes(x);
	int i = x + 1;
	for(;;)
	{
		if(countOnes(i) == ones)
		{
			std::cout<<i<<std::endl;
			break;
		}
		i++;
	}
	i = x - 1;
	for(;;)
	{
		if(countOnes(i) == ones)
		{
			std::cout<<i<<std::endl;
			break;
		}
		i--;
	}
}
int snlBetter(int n)
{
	int i = 0;
	while(((1<<i) & n) == 0)
		i++;
	n = ((1<<i) ^ n);
	
	int pos = i;
	i = pos-1;
	while(((1<<i) & n) != 0)
	{
		i--;
	}
	int smallest = n ^ (1<<i);
	std::cout<<smallest<<std::endl;

	i = pos+1;
	while(((i<<1) & n) != 0)
	{
		i++;
	}
	int largest = n ^ (1<<i);
	std::cout<<largest<<std::endl;
}
int main()
{
	snlBetter(1000);
}
