#include<iostream>
#include<algorithm>
#include<vector>
int maximumGap(std::vector<int>& v)
{
	if(v.size() < 2)
		return 0;
	int small = std::min(v[0], v[1]);
	int large = std::max(v[0], v[1]);
	
	for(auto it = v.begin()+2; it<v.end(); it++)
	{
		if(small-*it >= large-small)
		{
			large = small;
			small = *it;
		}
		else if(*it - large >= large-small)
		{
			small = large;
			large = *it;
		}
		else if(*it >= small && *it <= large)
		{
			if(*it-small > small-*it)
			{
				large = *it;
			}
			else
			{
				small = *it;
			}
		}
		//std::cout<<small<<" "<<large<<std::endl;
	}
	std::cout<<small<<" "<<large<<" First"<<std::endl;
	
	for(auto it = v.rbegin(); it < v.rend(); it++)
	{
		if(small-*it > large-small)
		{
			large = small;
			small = *it;
		}
		else if(*it - large > large-small)
		{
			small = large;
			large = *it;
		}
		else if(*it > small && *it < large)
		{
			if(*it-small > small-*it)
			{
				large = *it;
			}
			else
			{
				small = *it;
			}
		}
		std::cout<<small<<" "<<large<<std::endl;
	}
	return large-small;
}
int main()
{
	std::vector<int> v;
	v.push_back(3);
	v.push_back(6);
	v.push_back(9);
	v.push_back(1);
	std::cout<<maximumGap(v);
}
