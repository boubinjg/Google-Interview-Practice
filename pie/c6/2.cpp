#include<iostream>
#include<algorithm>
#include<unordered_map>
std::string eraseIf(std::string str, std::string chars)
{
	std::unordered_map<char, bool> map;
	std::string ret;
	for(auto it = chars.begin(); it<chars.end(); it++)
		map[*it] = true;
	for(auto it = str.begin(); it<str.end(); it++)
		if(!map[*it])
			ret+=*it;
	return ret;		
}
int main()
{
	std::cout<<eraseIf("abcdabcdabcd", "ab")<<std::endl;
}
