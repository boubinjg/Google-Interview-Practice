#include<iostream>
#include<algorithm>
#include<vector>
struct node{ 
	int i;
	int j;
};
void printVector(std::vector<std::vector<int> > v)
{
	for(int i = 0; i<v.size(); i++)
	{
		for(int j = 0; j<v.size(); j++)
		{
			std::cout<<v[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
int findCol(std::vector<int> v, int val, int begin, int end)
{
	if(begin > end)
		return -1;
	int middle = (begin+end)/2;
	if(v[middle] == val)
		return middle;
	else if(v[middle] > val)
		return findCol(v, val, begin, middle-1);
	else
		return findCol(v, val, middle+1, end);
}
node findRow(std::vector<std::vector<int> > v,int val, int begin, int end)
{
	node n;
	if(begin > end)
	{
		n.i = -1;
		n.j = -1;
		return n;
	}
	int middle = (begin+end)/2;
	if(v[middle][0] <= val && v[middle][v.size()-1] >= middle)
	{
		n.i = middle;
		int f = findCol(v[middle], val, 0, v.size()-1);
		if(f != -1)
		{
			n.j = f;
			return n;
		}
		else
		{
			node l = findRow(v, val, middle+1, end);
			node u = findRow(v, val, begin, middle-1);
			if(l.j > 0)
				return l;
			else
				return u;
		}
		
	} 
	if(v[middle][end] < val)
	{
		return findRow(v,val,middle+1, end);
	}
	else
		return findRow(v, val, begin, middle-1);
	
}
int main()
{
	std::vector<std::vector<int> > v;
	
	for(int i = 0; i<10; i++)
	{
		std::vector<int> n;
		for(int j = 0; j<10; j++)
		{
			n.push_back(10*i + j);
		}
		v.push_back(n);
	}
	printVector(v);
	v[5][5] = 56;
	node n = findRow(v, 55, 0, 9);
	std::cout<<n.i<<" "<<n.j<<std::endl;
	return 0;
}
