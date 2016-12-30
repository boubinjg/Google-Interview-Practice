#include <string>
#include <iostream>
bool isOneOff(std::string s1, std::string s2)
{
	int count = 0;
	if(s1.length() > s2.length())
	{
		for(int i = 0; i<s1.size(); i++)
			if(s1[i] != s2[i-count])
				count++;
		if(count <= 1)
			return true;
		return false;
	}
	else if(s2.length() > s1.length())
	{
		for(int i = 0; i<s2.size(); i++)
			if(s2[i] != s1[i-count])
				count++;
		if(count <= 1)
			return true;
		return false;
	}
	else
	{
		for(int i = 0; i<s1.size(); i++)
		{
			if(s1[i] != s2[i])
				count++;
		}
		if(count <= 1)
			return true;
		return false;
	}	
}
int main()
{
	std::cout<<isOneOff("palse","plse")<<isOneOff("plse","palse")<<isOneOff("palse","balse")<<std::endl;
	std::cout<<isOneOff("palbe","plse")<<isOneOff("","a")<<isOneOff("asdf","fdsa")<<std::endl;
}
