//see if two numbers are equal without using comparison operators
#include<iostream>
bool isEqual(int a, int b)
{
	return !(a-b);
}
int main()
{
	std::cout<<isEqual(5,5)<<" "<<isEqual(5,6)<<" "<<isEqual(6,5)<<std::endl;
}
