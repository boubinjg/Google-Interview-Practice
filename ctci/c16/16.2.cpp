#include<iostream>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<algorithm>
int occurance(std::unordered_map<std::string, int> map, std::string word)
{
	return map[word];
}
std::unordered_map<std::string, int> readMap(std::string fname)
{
	std::fstream myfile(fname);
	std::string line;
	std::unordered_map<std::string, int> map;
	while(getline(myfile, line))
	{
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		map[line]++;
	}	
	
	return map;

}
int main()
{
	std::unordered_map<std::string, int> map = readMap("16.2.txt");
	std::cout<<occurance(map, "thing")<<std::endl;
}
