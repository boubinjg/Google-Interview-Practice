#include<algorithm>
#include<string>
#include<iostream>
int main()
{
	std::string s = "abcdefg";
	std::reverse(s.begin(),s.end());
	std::cout<<s<<std::endl;
}
