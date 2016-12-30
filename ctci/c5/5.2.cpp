#include<iostream>
int printFloat(double f)
{
	double div = 1;
	std::string s = "";
	for(int i = 0; i<32; i++)
	{
		if(f >= div)
		{
			s += "1";
			f-=div;
		}
		else
			s += "0";
		div /= 2;
	}

	if(f > 0)
		std::cout<<"ERROR"<<std::endl;
	else
		std::cout<<s<<std::endl;
}
int main()
{
	printFloat(.875);
}
