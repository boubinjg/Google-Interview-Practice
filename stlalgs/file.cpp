#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
int main()
{
	std::ifstream infile("readme.txt");
	std::string line;
	while(std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string a;
		std::cout<<"line "<<line<<std::endl;
		while(std::getline(iss,a,',')) 
		{
			std::cout<<a<<std::endl;
		}
		std::cout<<std::endl;
	}
	return 0;
}
