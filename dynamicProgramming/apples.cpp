#include<vector>
#include<iostream>
struct node{
	int i;
	int j;	
};
std::vector<std::vector<int> > memo;
int sum(std::vector<node> v, std::vector<std::vector<int> > nums)
{
	int sum = 0;
	for(int i = 0; i<v.size(); i++)
		sum+= nums[v[i].i][v[i].j];
	return sum;
}
void printSingle(std::vector<node> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<" ("<<v[i].i<<","<<v[i].j<<") "<<std::endl;
	std::cout<<std::endl;
}
void printVec(std::vector<std::vector<int> > v)
{
	for(int i = 0; i<v.size(); i++)
	{
		for(int j = 0; j<v.size(); j++)
			std::cout<<v[i][j]<<" ";
		std::cout<<std::endl;
	}
}
std::vector<std::vector<int> > setZero(std::vector<std::vector<int> >& v, std::vector<node> n)
{
	for(int i = 0; i<n.size(); i++)
		v[n[i].i][n[i].j] = 0;
	return v;
}
std::vector<node> calcVal(std::vector<std::vector<int> >& v, int i, int j, std::vector<node> rv)
{
	int l=0, u=0;
	node n;
	n.i = i;
	n.j = j;
	rv.push_back(n);
	std::vector<node> lv=rv, uv=rv;
	if(j>0)
	{
		lv = calcVal(v, i, j-1, lv);
	}
	if(i>0)
	{
		uv = calcVal(v, i-1, j, uv);
	}
	if(sum(lv, v) > sum(uv, v))
		return lv;
	else
		return uv;
}
int findApples(std::vector<std::vector<int> >& v)
{
	std::vector<node> lv;
	std::vector<node> uv; 
	int pos = v.size()-1, val = v[pos][pos];
	node cur;
	cur.i = pos;
	cur.j = pos;
	lv.push_back(cur);
	uv.push_back(cur);
	
	int l, u;
	
	lv = calcVal(v, pos, pos-1, lv);
	uv = calcVal(v, pos-1, pos, uv);
	
	l = sum(lv, v);
	u = sum(uv, v);
	if(l > u)
	{
		
		v = setZero(v, uv);
		printSingle(uv);
		return l;
	}
	else
	{
		v = setZero(v, lv);
		printSingle(lv);
		return u;	
	}
}
int main()
{
	std::vector<std::vector<int> > v;
	for(int i = 0; i<10; i++)
	{
		std::vector<int> n;
		for(int j = 0; j<10; j++)
		{
			n.push_back(i*j + j + 10);
		}
		v.push_back(n);
	}
	printVec(v);
	std::cout<<std::endl;
	int count = findApples(v);
	printVec(v);
	count += findApples(v);
	printVec(v);
	count += findApples(v);
	printVec(v);
	std::cout<<count<<std::endl;
	return 0;
}
