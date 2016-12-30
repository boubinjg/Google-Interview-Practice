#include<iostream>
int numBitstoSwap(int n, int m)
{
	int count = 0;
	for(int i = 0; i<32; i++)
	{
		int c = (1<<i);
		bool n1 = ((c & n) == 0);
		bool m1 = !((c & m) == 0);
		if(m1 == n1)
			count++;
	}
	return count;
}
int main()
{
	std::cout<<numBitstoSwap(29, 15)<<std::endl;
}
