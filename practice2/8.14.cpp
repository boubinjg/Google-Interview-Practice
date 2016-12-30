#include<iostream>
#include<string>
int numTrue(std::string exp, bool b)
{
	if(exp.length() == 1)
		return exp[0]-'0' == b;
	int total = 0;
	for(int i = 1; i<exp.length(); i+=2)
	{
		std::string left = exp.substr(0, i);
		std::string right = exp.substr(i+1);
		std::cout<<left<<" "<<right<<std::endl;

		int lTrue = numTrue(left, true);
		int rTrue = numTrue(right, true);
		int lFalse = numTrue(left, false);
		int rFalse = numTrue(right, false);
	
		int totalIt = 0;
		
		if(exp[i] == '|')
			totalIt += lTrue*rTrue + lTrue*rFalse + rTrue*lFalse;
		else if(exp[i] == '&')
			totalIt += rTrue*lTrue;
		else if(exp[i] == '^')
			totalIt += lTrue*rFalse + lFalse * rTrue;

		total += totalIt;
	}

	return total;
	
}
int main()
{
	std::string exp = "1&1&1";
	std::cout<<numTrue(exp, true)<<std::endl;
}
