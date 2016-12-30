#include<vector>
#include<iostream>
std::vector<int> merge(std::vector<int> l, std::vector<int> r)
{
	std::vector<int> result;
	while(l.size() > 0 && r.size() > 0)
	{
		if(l[0] > r[0])
		{
			result.push_back(r[0]);
			r.erase(r.begin());
		}
		else
		{
			result.push_back(l[0]);
			l.erase(l.begin());
		}
	}
	while(l.size() > 0)
	{
		result.push_back(l[0]);
		l.erase(l.begin());
	}
	while(r.size() > 0)
	{
		result.push_back(r[0]);
		r.erase(r.begin());
	}
	return result;
}
int main()
{
	std::vector<int> l, r;
	for(int i = 0; i<10; i++)
	{
		l.push_back(i);
		r.push_back(i-1);
	}
	std::vector<int> m = merge(l, r);
	for(int i = 0; i<m.size(); i++)
	{
		std::cout<<m[i]<<std::endl;
	}
}
