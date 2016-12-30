#include<iostream>
#include<vector>
#include<algorithm>
void printParens(int open, int close, std::string s)
{
	if(open == 0 && close == 0)
	{
		std::cout<<s<<std::endl;
	}
	if(open)
		printParens(open-1, close, s+"(");
	if(close && open < close)
		printParens(open, close-1, s+")");
}
void parenPerm(int n, std::string s)
{
	printParens(n-1,n,"(");
}
int main()
{
	parenPerm(3, "");
}
