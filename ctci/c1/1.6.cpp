#include <string>
#include <iostream>
std::string compress(std::string s)
{
	std::string ret = "";
	for(int i = 0; i<s.length(); i++)
	{
		int count = 1;
		char c = s[i];
		for(int j = i+1; j<s.length(); j++)
		{
			if(s[j] == c)
				count++;
			else
				break;
		}
		ret += c;
		if(count > 1)
			ret += std::to_string(count);
		i += count-1;
	}
	return ret;
}
int main()
{
	std::string s = "aabbbbcc";
	std::cout<<compress(s)<<std::endl;
}
