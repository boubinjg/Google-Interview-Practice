#include<unordered_map>
#include<iostream>
#include<string>
int firstUnrep(std::string s)
{
	std::unordered_map<char, int> map;
	for(auto it = s.begin(); it<s.end(); it++)
		map[*it]++;
	for(auto it = s.begin(); it<s.end(); it++)
		if(map[*it] == 1)
			return (char)(*it);
}
int main()
{
	std::cout<<(char)firstUnrep("total")<<std::endl;
}
