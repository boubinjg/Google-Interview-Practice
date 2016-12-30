#include <string>
#include <algorithm>
#include <iostream>
int checkPerm(std::string s1, std::string s2)
{
	if(s2.size() != s1.size())
		return false;
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	return s1==s2;
}
int main()
{
	std::cout<<checkPerm("12345", "15432")<<" "<<checkPerm("1234", "12354")<<std::endl;
	std::cout<<checkPerm("1234", "abcd")<<std::endl;
}
