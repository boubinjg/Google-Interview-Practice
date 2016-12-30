#include<iostream>
void swap(int x, int y)
{
	std::cout<<x<<" "<<y<<std::endl;
	y -= x;
	x += y;
	y = x-y;
	std::cout<<x<<" "<<y<<std::endl;
}
int main()
{
	swap(-2, 100);
	return 0;
}
