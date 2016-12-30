#include<iostream>
int swapBits(int x)
{
	//sifts all the odd bits (AA) to the right, shifts all the evens to the left
	//the merges them using an or.
	return (((x & 0xaaaaaaaa) >>1) | ((x & 0x55555555) << 1));
}
int main()
{
	std::cout<<swapBits(100)<<std::endl;;
}
