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
void makeZero(std::vector<std::vector<int> >& v)
{
	std::vector<bool> row(v.size());
	std::vector<bool> col(v.size());

	for(int i = 0; i<v.size(); i++)
		for(int j = 0; j<v.size(); j++)
			if(v[i][j] == 0)
			{
				col[i] = true;
				row[j] = true;
			}
	for(int i = 0; i<v.size(); i++)
		for(int j = 0; j<v.size(); j++)
			if(col[i] || row[j])
			{
				v[i][j] = 0;
			}
}
int main()
{
	std::vector<std::vector<int> > v;
	for(int i = 1; i<10; i++)
	{
		std::vector<int> n;
		for(int j = 1; j<10; j++)
			n.push_back(j);
		v.push_back(n);
	}
	v[2][3] = 0;
	v[1][4] = 0;
	print(v);
	makeZero(v);
	print(v);
}
