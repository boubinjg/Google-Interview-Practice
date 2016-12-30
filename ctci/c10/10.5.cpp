#include<iostream>
#include<vector>
#include<string>
int findVal(std::vector<std::string> v, int start, int end, std::string val, std::string last)
{
	if(start > end)
		return -1;
	int middle = (start+end)/2;
	int i = middle;
	while(v[i] == "")
		i--;
	if(v[i] == last)
	{
		i = middle+1;
		while(v[i] == "")
			i++;
	}	
	middle = i;
	if(v[middle] == val)
		return middle;
	if(v[middle] > val)
		return findVal(v, start, middle-1, val, v[middle]);
	else
		return findVal(v, middle+1, end, val, v[middle]);
}
int main()
{
	std::vector<std::string> v;
	v.push_back("abc");
	v.push_back("");
	v.push_back("");
	v.push_back("");
	v.push_back("");
	v.push_back("def");
	v.push_back("");
	v.push_back("");
	v.push_back("g");
	v.push_back("");
	v.push_back("");
	v.push_back("hij");
	
	std::cout<<findVal(v, 0, v.size()-1, "def", "")<<std::endl;
	
	return 0;
}
