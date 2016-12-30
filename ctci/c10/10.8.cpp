#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
int findDups(std::vector<int> v)
{
	std::vector<bool> b(32000);
	for(int i = 0; i<v.size(); i++)
	{
		if(b[v[i]])
			std::cout<<v[i]<<std::endl;
		else
			b[v[i]] = true;	
	}
}
int main()
{
	std::vector<int> v;
	for(int i = 1; i<32000; i++)
	{
		v.push_back(i);
		if(i%100 == 0)
			v.push_back(i);
	}
	findDups(v);
}
