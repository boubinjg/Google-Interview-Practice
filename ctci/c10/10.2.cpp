#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
bool anaCmp(std::string s1, std::string s2)
{
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	return s1 > s2;
}
int main()
{
	std::vector<std::string> s;
	s.push_back("string");
	s.push_back("ntrsig");
	s.push_back("a");
	s.push_back("b");
	s.push_back("p");
	std::sort(s.begin(), s.end(), anaCmp);
	for(int i = 0; i<s.size(); i++)
		std::cout<<s[i]<<std::endl;
	return 0;
}
