#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
int largest(std::vector<int> v)
{
	int maxHeight = 0;
	for(auto it = v.begin(); it<v.end(); it++)
		if(maxHeight < *it)
			maxHeight = *it;
	int ret = maxHeight;
	for(int i = 0; i<v.size(); i++)
	{
		int height = v[i];
		int width = 1;
		for(int j = i+1; j<v.size(); j++)
		{	
			if(v[j] <height)
				height = v[j];	
			width++;
			if(width*height > ret)
				ret = width*height;
		}
	}
	return ret;
}
int main()
{
	std::vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(5);
	v.push_back(6);
	v.push_back(2);
	v.push_back(3);
	std::cout<<largest(v)<<std::endl;
	return 0;
}
