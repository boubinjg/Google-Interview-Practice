#include <vector>
#include <iostream>
void print(std::vector<std::vector<int> > v)
{
	for(int i = 0; i<v.size(); i++)
	{
		for(int j = 0; j<v.size(); j++)
			std::cout<<v[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<std::endl;	
}
void rotate90(std::vector<std::vector<int> >& v)
{
	for(int i = 0; i<v.size(); i++)
	{
		for(int j = 0; j<v[i].size()/2; j++)
		{
			std::swap(v[i][j], v[i][v.size()-j-1]);
		}
	}
	
	for(int i = 0; i<v.size(); i++)
	{
		for(int j = 0; j<v.size(); j++)
		{
			if(i+j < v.size())
				std::swap(v[i][j], v[v.size()-j-1][v.size()-i-1]);
		}
	}
} 
int main()
{
	std::vector<std::vector<int> > v;
	for(int i = 0; i<10; i++)
	{
		std::vector<int> n;
		for(int j = 0; j<10; j++)
			n.push_back(j);
		v.push_back(n);
	}
	print(v);
	rotate90(v);
	print(v);
}
