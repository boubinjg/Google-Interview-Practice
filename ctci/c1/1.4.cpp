#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
bool isPalPerm(std::string s)
{
	std::sort(s.begin(), s.end());
	bool foundMiddle = false;
        int count = 0;
	char last = s[0];
	if(s.size() == 1)
		return true;
	for(int i = 1; i<s.size(); i++)
	{
		if(s[i] != last && count %2 == 1)
		{
			if(foundMiddle)
				return false;
			foundMiddle = true;
			count = 1;
			last = s[i];
		}
		else if(s[i] == last)
			count++;
		else
		{
			count = 1;
			last = s[i];
		}
	}	
	if(count %2 == 1 && foundMiddle)
		return false;
	return true;
}
bool isPalPermBetter(std::string s)
{
	std::vector<bool> boolVec(26);
	for(int i = 0; i<s.size(); i++)
		boolVec[s[i]-'a'] = !boolVec[s[i]-'a'];
	int count = 0;
	for(int i = 0; i<boolVec.size(); i++)
	{
		if(boolVec[i])
			count++;
	}
	std::cout<<count<<" ";
	if(count > 1)
		return false;
	return true;
}
int main()
{
	std::cout<<isPalPermBetter("aaabb")<<std::endl;
	std::cout<<isPalPermBetter("aaabbb")<<std::endl;
	std::cout<<isPalPermBetter("aabbbcc")<<std::endl; 
}
