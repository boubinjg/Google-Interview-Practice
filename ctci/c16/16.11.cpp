#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
std::unordered_map<std::string, bool> map;
std::unordered_map<std::string, int> memo;
int buildBoard(int k, int shorter, int longer, int curLen, std::string lengths)
{
	if(curLen == k)
	{ 
		std::sort(lengths.begin(), lengths.end());
		if(map[lengths])
			return 0;
		map[lengths] = true;
		return 1;
	}
	if(curLen > k)
		return 0;
	
	std::sort(lengths.begin(), lengths.end());
	if(memo[lengths] > 0)
		return 0;
	else
	memo[lengths] =  buildBoard(k, shorter, longer, curLen + shorter, lengths+std::to_string(shorter)) + 
	                 buildBoard(k, shorter, longer, curLen+longer, lengths+std::to_string(longer));
	return memo[lengths];
}
int main()
{
	std::cout<<buildBoard(5, 1, 2, 0, "")<<std::endl;
	return 0;
}
