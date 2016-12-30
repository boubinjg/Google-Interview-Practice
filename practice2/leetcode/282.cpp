#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
void calcNum(int total, int targ, std::string rem, std::string created, std::vector<std::string>& ret)
{
	if(rem == "" && total == targ)
	{
		ret.push_back(created);
	}
	else if(rem != "")
	{
		if(created == "")
		{
			created = rem[0];
			total = rem[0]-'0';
			rem = rem.substr(1);
			calcNum(total, targ, rem, created, ret);
		}
		else
		{
			std::string oldrem = rem;
			calcNum(total+(rem[0]-'0'), targ, rem.substr(1), created+"+"+oldrem[0], ret);
			calcNum(total*(rem[0]-'0'), targ, rem.substr(1), created+"*"+oldrem[0], ret);
			calcNum(total-(rem[0]-'0'), targ, rem.substr(1), created+"-"+oldrem[0], ret);
		}
	}
}
std::vector<std::string> addOperators(std::string num, int target)
{
	std::vector<std::string> ret;
	calcNum(0, target, num, "", ret);
	return ret; 
}
int main()
{
	std::vector<std::string> v = addOperators("123", 6);
	for(auto it = v.begin(); it<v.end(); it++)
		std::cout<<*it<<std::endl;


}
