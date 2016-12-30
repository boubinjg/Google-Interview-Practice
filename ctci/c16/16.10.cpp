#include<iostream>
#include<vector>
#include<queue>
std::vector<int> v(101);
std::priority_queue<int, std::vector<int>, std::greater<int> > birth;
std::priority_queue<int, std::vector<int>, std::greater<int> > death;
int maxYearOp()
{
	int count = 0;
	int max = 0;
	while(!death.empty() && !birth.empty())
	{
		if(death.top() < birth.top())
		{
			if(count > max)
				max = count;
			death.pop();
			count--;
		}
		else
		{
			birth.pop();
			count++;
		}
	}		
	if(count > max)
		max = count;
	return max;
}
int findMaxYear()
{
	int ret;
	for(int i = 0; i<v.size(); i++)
		if(v[i] > v[ret])
			ret = i;
	return 1900+ret;			
}
void addPerson(int by, int dy)
{
	for(int i = by-1900; i<= dy-1900; i++)
		v[i]++;
	birth.push(by);
	death.push(dy + 1);
}

int main()
{
	addPerson(1950, 1966);
	addPerson(1945, 1951);
	addPerson(1932, 1950);
	addPerson(1945, 1999);
	addPerson(1999, 2000);
	std::cout<<findMaxYear()<<std::endl;
	std::cout<<maxYearOp()<<std::endl;
}
