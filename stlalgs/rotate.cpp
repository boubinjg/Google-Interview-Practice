#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
int main()
{
	//rotate takes a section of a vector (for instance v.begin - v.begin + 5, and reorders the vector
	//so that that section ends at another position (v.end)
	std::vector<int> v{1,2,3,4,5,6,7,8,9};
	std::rotate(v.begin(), v.begin()+5, v.end());
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<std::endl;
}
