#include<vector>
#include<iostream>
bool done;
void printGrid(std::vector<std::vector<char> > g)
{
	for(int i = 0; i<g.size(); i++)
	{
		for(int j = 0; j<g[i].size(); j++)
			std::cout<<g[i][j];
		std::cout<<std::endl;
	}
}
bool findPath(std::vector<std::vector<char> >& g, int i, int j)
{
	if(!done)
	{
		if(g[i][j] == 'X')
			return false;
		else if(i == 9 && j == 9)
		{	
			done = true;
			printGrid(g);
			std::cout<<std::endl;
		}
		else
		{
			g[i][j] = 'P';
			bool l, d;
			if(i < 9)
				l = findPath(g, i+1, j);
			if(j < 9)
				d = findPath(g, i, j+1);
			if(!(d || l))
			{
				g[i][j] = 'O';
				return false;
			}
			return true;
		}
	}
}
int main()
{
	std::vector<std::vector<char> > v;
	for(int i = 0; i<10; i++)
	{
		std::vector<char> c;
		v.push_back(c);
		for(int j = 0; j<10; j++)
			v[i].push_back('O');
	}
	v[2][5] = 'X';
	v[4][9] = 'X';
	v[5][6] = 'X';
	v[6][2] = 'X';
	v[3][2] = 'X';
	v[8][0] = 'X';
	v[7][1] = 'X';
	findPath(v, 0, 0);
	printGrid(v);
}
