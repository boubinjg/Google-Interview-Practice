#include<iostream>
#include<vector>
int findVal(std::vector<int> v, int val, int begin, int end)
{
	
	if(begin > end)
		return -1;
	else
	{
		int middle = (begin + end)/2;
		if(v[middle] == val)
			return middle;
		else if(v[middle] < val)
		{
			int fv = findVal(v, val, middle+1, end);
			if(fv == -1)
				return findVal(v, val, begin, middle-1);
			return fv;
		}
		else 	
		{
			int fv = findVal(v, val, middle-1, end);
			if(fv == -1)
				return findVal(v, val, middle+1, end);
			return fv;
		}
	}
}
int main()
{
	std::vector<int> v;
	v.push_back(15);
	v.push_back(16);
	v.push_back(19);
	v.push_back(20);
	v.push_back(25);
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(7);
	v.push_back(10);
	v.push_back(14);

	std::cout<<findVal(v, 19, 0, 11)<<std::endl;
	return 0;
}
