#include<iostream>
#include<stack>
void perm(std::string prefix, std::string rest)
{
	if(rest == "")
		std::cout<<prefix<<std::endl;
	else
	{
		for(int i = 0; i<rest.length(); i++)
		{
			std::string next = prefix+rest[i];
			std::string remaining = rest.substr(0,i) + rest.substr(i+1);
			std::cout<<"rest = "<<next<<" remaining = "<<remaining<<std::endl;
			perm(next, remaining);
		}
	}
}
int main()
{
	perm("","abcd");
}
