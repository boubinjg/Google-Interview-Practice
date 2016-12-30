#include<iostream>
#include<string>
void permutations(std::string perm, std::string left)
{
	if(left == "")
		std::cout<<perm<<std::endl;
	else
	{
		for(int i = 0; i<left.size(); i++)
		{
			std::string nperm = perm+left[i];
			std::string nleft = left.substr(0,i) + left.substr(i+1);
			permutations(nperm, nleft);
		}
	}
}
int main()
{
	permutations("","abcd");
}
