#include<iostream>
#include<string>
#include<sstream>
double calc(std::string s)
{
	double res = 0;
	std::string addline;
	std::istringstream iss(s);
	while(std::getline(iss, addline, '+'))
	{
		std::string mulline;
		std::istringstream mss(addline);
		double mulRet = 1;
		while(std::getline(mss, mulline, '*'))
		{
			std::string divline;
			std::istringstream dss(mulline);
			double divRet = 1;
			int divCount = 0;
			while(std::getline(dss, divline, '/'))
			{
				if(divCount == 0)
					divRet = stof(divline);
				else
					divRet /= stof(divline);
				divCount++;
			}
			mulRet *= divRet;
		}
		res += mulRet;
	}
	return res;
}
int main()
{
	std::cout<<calc("5*2+4+55/5")<<std::endl;
}
