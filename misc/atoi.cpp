#include <iostream>
#include <algorithm>
int ati(std::string s)
{
	int length = s.length();
	int number = 0;
	int power = 1;
	for(int i = s.length()-1; i>=0; i--)
	{
		number += ((s[i]- '0') * power);
		power *= 10;
	}
	return number;
}
int main()
{
	std::string s = "5678";
	std::cout<<ati(s)<<std::endl;
}
