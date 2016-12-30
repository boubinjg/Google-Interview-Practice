#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
int calcMinus(std::string s)
{
	std::istringstream iss(s);
	std::string line;
	int ret = 0;
	bool first = true;
	while(std::getline(iss, line, '-'))
	{
		if(first)
		{
			ret += std::stoi(line);
			first = false;
		}
		else 
			ret -= std::stoi(line);
	}
	return ret;
}
int calcPlus(std::string s)
{
	std::istringstream iss(s);
	std::string line;
	int ret = 0;
	while(std::getline(iss, line, '+'))
	{
		if(std::find(line.begin(), line.end(), '-') != line.end())
		{	
			ret += calcMinus(line);
		}
		else 
			ret += std::stoi(line);
	}
	return ret;
}
int sTermFinal(std::string s)
{
	s.erase(std::remove(s.begin(), s.end(),' '), s.end());
	s.erase(std::remove(s.begin(), s.end(),'('), s.end());
	s.erase(std::remove(s.begin(), s.end(),')'), s.end());
	std::cout<<s<<std::endl;	
	return calcPlus(s);
}
int main()
{
	std::cout<<sTermFinal("( ( 1 + 2 )  ) + ( 3 - 4 )")<<std::endl;
	return 0;
}
