#include <iostream>
#include <algorithm>
#include <string>
int main()
{
	std::string s = ";lkasdf;laksga;lksdjfa;sldkjfa;sdlfhvpoiufaafupouipoiuapsoidufpasdfasdfasdfasdf";
	std::string maxpal = "";
	for(int i = 0; i<s.length(); i++)
	{
		for(int j = i; j<=s.length(); j++)
		{
			std::string sub = s.substr(i, j-i);
			std::string rev = sub;
			std::reverse(rev.begin(), rev.end());
			if(rev == sub && rev.length() > maxpal.length())
				maxpal = sub;
				
		}
	}
	std::cout<<maxpal<<std::endl;
}
