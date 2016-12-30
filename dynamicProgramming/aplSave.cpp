#include<vector>
#include<iostream>
struct node{
	
};
int sum(std::vector<int> v)
{
	int sum = 0;
	for(int i = 0; i<v.size(); i++)
		sum+=v[i];
	return sum;
}
void printSingle(std::vector<int> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
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
std::vector<int> calcVal(std::vector<std::vector<int> >& v, int i, int j, std::vector<int> rv)
{
	int l=0, u=0;
	rv.push_back(v[i][j]);
	std::vector<int> lv=rv, uv=rv;
	if(j>0)
	{
		lv = calcVal(v, i, j-1, lv);
	}
	if(i>0)
	{
		uv = calcVal(v, i-1, j, uv);
	}
	//if(i==0 && j==0)
	//	return v[i][j];
	if(sum(lv) > sum(uv))
		return lv;
	else
		return uv;
}
int findApples(std::vector<std::vector<int> >& v)
{
	std::vector<int> lv;
	std::vector<int> uv; 
	int pos = v.size()-1, val = v[pos][pos];
	lv.push_back(val);
	uv.push_back(val);
	
	int l, u;
	
	lv = calcVal(v, pos, pos-1, lv);
	uv = calcVal(v, pos-1, pos, uv);
	
	l = sum(lv);
	u = sum(uv);
	if(l > u)
	{
		printSingle(uv);
		return l;
	}
	else
	{
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
	std::cout<<findApples(v)<<std::endl;
	printVec(v);
	return 0;
}
