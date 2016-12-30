#include<iostream>
#include<vector>
void printVec(std::vector<std::vector<int> > v)
{
	for(int i = 0; i<v.size(); i++)
	{
		for(int j = 0; j<v.size(); j++)
			std::cout<<v[i][j]<<" ";
		std::cout<<std::endl;
	}
}
void fill(std::vector<std::vector<int> >& v, int i, int j, int oc, int nc)
{
	if(v[i][j] == oc)
	{
		v[i][j] = nc;
		if(i < v.size()-1)
			fill(v, i+1, j, oc, nc);
		if(j < v.size()-1)
			fill(v, i, j+1, oc, nc);
		if(i != 0)
			fill(v, i-1, j, oc, nc);
		if(j != 0)
			fill(v, i, j-1, oc, nc);
		if(j != 0 && i != 0)
			fill(v,i-1,j-1,oc, nc);
		if(j != 0 && i < v.size()-1)
			fill(v, i+1, j-1, oc, nc);
		if(j < v.size()-1 && i != 0)
			fill(v,i-1, j+1, oc, nc);
		if(j < v.size()-1 && i < v.size()-1)
			fill(v, i+1, j+1, oc, nc);
	}
}
int main()
{
	std::vector<std::vector<int> > v;
	for(int i = 0; i<10; i++)
	{	
		std::vector<int> n;
		for(int j = 0; j<10; j++)
			n.push_back(1);
		v.push_back(n);
	}
	for(int i = 4; i<8; i++)
	{
		for(int j = 3; j<8; j++)
		{
			v[i][j] = 0;
		}
	}
	v[3][2] = 0;
	fill(v, 5, 5, v[5][5], 2);
	printVec(v);
}
