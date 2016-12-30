#include<iostream>
#include<algorithm>
int strToInt(std::string s)
{
	int ret = 0;
	bool neg = false;
	if(s[0] = '-')
	{
		neg = true;
		s.erase(s.begin());
	}
	for(auto it = s.begin(); it<s.end(); it++)
	{
		ret*=10;
		ret+= (*it)-'0';
	}
	if(neg)
		return -ret;
	return ret;
}
std::string intToString(int i)
{
	std::string ret = "";
	if(i<0)
	{
		ret+="-";
		i*=-1;
	}
	if(i == 0)
		ret = "0";
	std::string collect = "";
	while(i > 0)
	{
		collect += ((i%10)+'0');
		i/=10;
	}
	std::reverse(collect.begin(), collect.end());
	ret+= collect;
	return ret;
}
int main()
{
	int i = strToInt("-12345");
	std::cout<<i<<std::endl;
	std::string s = intToString(i);
	std::cout<<s<<std::endl;
}
