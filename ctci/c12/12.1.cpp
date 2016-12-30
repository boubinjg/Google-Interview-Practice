//print last K lines
#include<string>
#include<iostream>
#include<fstream>
#include<queue>
int printLastK(std::string fname, int k)
{
	std::ifstream myfile(fname);
	std::string line;
	std::deque<std::string> d;
	while(getline(myfile, line))
	{
		d.push_front(line);
		if(d.size() > k)
			d.pop_back();
	}
	while(!d.empty())
	{
		std::cout<<d.back()<<std::endl;
		d.pop_back();
	}
}
int main()
{
	printLastK("test.txt", 3);
}
