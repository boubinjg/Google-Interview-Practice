#include <iostream>
#include <vector>
#include<unordered_map>

std::unordered_map<int, int> map;
int upStairs(int n)
{
	int ret = 0;
	
	if(n > 0)
	{
		ret += upStairs(n-1);
	}
	if(n > 1) 
	{
		ret +=  upStairs(n-2);
	}
	if(n > 2)
	{
		if(map[n] != 0)
			ret += map[n];
		else
		{
			int val = upStairs(n-3);
			map[n] = val;
			ret += val;
		}
	}
	if(ret == 0)
		return 1;
	return ret;
}
int main()
{
	std::cout<<upStairs(35)<<std::endl;;	
}
