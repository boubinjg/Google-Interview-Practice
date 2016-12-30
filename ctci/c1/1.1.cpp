#include <string>
#include <iostream>
#include <vector>
bool allUniqueChars(std::string s)
{
	for(int i = 0; i<s.size(); i++)
		for(int j = 0; j<s.size(); j++)
		{
			if(i != j && s[i] == s[j])
				return false; 
		}
	return true;
}
bool allUniqueBetter(std::string s)
{
	if(s.length() > 128)
		return false;
	std::vector<bool> charsSeen(128);
	for(int i = 0; i<s.size(); i++)
	{
		if(charsSeen[s[i]])
			return false;
		charsSeen[s[i]] = 1;
	}
	return true;
}
int main()
{
	std::cout<<allUniqueChars("ABCDEFG")<<" "<<allUniqueChars("ABCDEFGG")<<std::endl;
	std::cout<<allUniqueBetter("ABCDEFG")<<" "<<allUniqueBetter("ABCDEFGG")<<std::endl;	
}
