#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
void printBin(double d)
{
	double p;
	std::string s = "";
	for(double i = 1; i<=32; i++)
	{
		p = pow(2.0,-i);
		if(d-p >= 0)
		{
			d-=p;
			s+="1";
		}
		else
			s+="0";
	}
	if(d != 0)
		std::cout<<"ERROR"<<std::endl;
	else
		std::cout<<s<<std::endl;
}
int main()
{
	printBin(.375);
}
