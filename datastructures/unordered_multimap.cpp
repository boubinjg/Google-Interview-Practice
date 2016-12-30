#include <unordered_map>
#include <iostream>

int main()
{
	std::unordered_multimap<int,int> map;
	map.insert(std::pair<int,int>(1,1));
	map.insert(std::pair<int,int>(1,2));
	map.insert({{1,3},{2,4}});
	for(auto it = map.begin(); it != map.end(); it++)
	{
		std::cout<< it->first<<" "<<it->second<<std::endl;
	}
}
