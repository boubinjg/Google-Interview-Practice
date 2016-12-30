#include<iostream>
#include<vector>
#include<algorithm>
void wigglesort(std::vector<int>& v)
{
	int average;
	for(auto it = v.begin(); it<v.end(); it++)	
		average+= *it;
	average/=v.size();

	std::vector<int> l;
	std::vector<int> r;

	for(auto it = v.begin(); it<v.end(); it++)
	{
		if(*it>average)
			r.push_back(*it);
		else
			l.push_back(*it);
	}

	for(int i = 0; i<v.size(); i+=2)
	{
		v[i] = l[i/2];
		v[i+1] = r[i/2];
	}
}
int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	
	wigglesort(v);

	for(auto it = v.begin(); it<v.end(); it++)
		std::cout<<*it<<std::endl;
}
