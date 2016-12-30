#include<iostream>
#include<regex>
#include<algorithm>
#include<string>
int main()
{
	std::regex r("\\s*(([0-9]*((.[0-9]+)?))e)?(([0-9]+)?((.[0-9]*)))\\s*");
	std::string s = " .";
	std::regex t("\\s*(([0-9]*((.[0-9]+)?))e)?(([0-9]+)((.[0-9]*)?))\\s*");
	std::cout<<regex_match(s, r)<<std::endl;
	std::string s2 = " .";
	std::cout<<regex_match(s2, t)<<std::endl;
}
