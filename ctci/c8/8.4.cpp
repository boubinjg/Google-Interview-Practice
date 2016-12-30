#include<iostream>
#include<vector>
void powerSet(std::vector<int> v)
{
	std::vector<std::vector<int> > ps;
	for(int i = 0; i<v.size(); i++)
	{
		int size = ps.size(), cur = v[i];
		for(int j = 0; j<size; j++)
		{
			std::vector<int> t = ps[j];
			t.push_back(cur);
			ps.push_back(t);
		}
		std::vector<int> temp;
		temp.push_back(v[i]);
		ps.push_back(temp);
	}
	for(int i = 0; i<ps.size(); i++)
	{
		for(int j = 0; j<ps[i].size(); j++)
		{
			std::cout<<ps[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
int main()
{
	std::vector<int> v;
	for(int i = 0; i<5; i++)
		v.push_back(i+1);
	powerSet(v);
}
