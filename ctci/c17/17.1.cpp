#include <iostream>
int add(int x, int y)
{
	while(y!=0)
	{
		int carry = x & y;
		x = x ^ y;
		y = carry << 1;
	}
	return x;
}
int main()
{
	std::cout<<add(15, 31)<<std::endl;
}
