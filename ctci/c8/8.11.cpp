#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
std::vector<std::vector<int> > memo;
//std::unordered_map<int, int, int> m;
int rCoins(int n, std::vector<int> coins)
{
	if(n < 0)
		return 0;
	else if(n == 0)
		return 1;
	else if(memo[n][coins.size()] != 0)
		return memo[n][coins.size()];
	else if(n > 0)
	{
		int size = coins.size();
		int ret = 0;
		for(int i = 0; i < size; i++)
		{
			int largest = coins[coins.size()-1];
			ret += rCoins(n-largest, coins);
			coins.pop_back();
		}
		//memo[n][size] = ret;
		return ret;
	}
}
int iterCoins(int n)
{
      	 int count = 0;
	 for(int j = 0; j<=n; j+=25)
	  for(int k = 0; k<=n; k+=10)
	   for(int l = 0; l<=n; l+=5)
            for(int m = 0; m<=n; m++)
	    {
		if((j + k + l + m) == n)
		 count++;
            }
	return count;
}
int main()
{
	std::vector<int> v;
	v.push_back(25);
	v.push_back(10);
	v.push_back(5);
	v.push_back(1);
	for(int i = 0; i<=1000; i++)
	{
		std::vector<int> n;
		for(int j = 0; j<=5; j++)
		{
			n.push_back(0);
		}
		memo.push_back(n);
	}
	std::cout<<rCoins(1000,v)<<std::endl;
}
