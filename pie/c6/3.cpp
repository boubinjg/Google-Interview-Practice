#include<iostream>
#include<string>
#include<sstream>
void reverseWords(std::string& s)
{
	std::string word;
	std::string ret = "";
	std::istringstream iss(s);
	while(std::getline(iss, word, ' '))
	{
		ret = word+" "+ret;
	}
	s = ret;
}
int main()
{
	std::string s = "aaaa bbbb cccc dddd";
	reverseWords(s);
	std::cout<<s<<std::endl;
	return 0;
}
