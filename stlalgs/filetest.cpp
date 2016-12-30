#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
int main()
{
	std::ifstream myfile("readme.txt");
	std::string line;
	std::outfstr ="";
	while(getline(myfile, line))
	{
		std::istringstream iss(line);
		std::string output;
		while(getline(iss, output, ','))
		{
			std::cout<<std::stoi(output)<<std::endl;
			outfstr += output;
		}
	}
	std::ofstream outfile("outfile");
	if(outfile.isopen())
	{
		outfile << outfstr;
	}
}
