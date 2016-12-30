#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
std::string urlifyEasy(std::string s)
{
	std::string ret;
	for(int i = 0; i<s.size(); i++)
	{
		if(s[i] == ' ')
			ret+= "%20";
		else
			ret+=s[i];
	}
	return ret;
}
int main()
{
	std::cout<<urlifyEasy("string test 1 2 3")<<std::endl;

}
