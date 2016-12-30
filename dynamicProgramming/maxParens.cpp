#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
int findMaxParens(bool val, std::string exp)
{
	if(exp == "1" && val)
		return 1;
	else if(exp == "1")
		return 0;
	else if(exp == "0" && val)
		return 0;
	else if(exp == "0")
		return 1;
	std::string l;
	std::string r; 
	std::string m;
	int ret = 0;
	for(int i = 1; i<exp.size(); i+=2)
	{
		
		l = exp.substr(0,i);
		r = exp.substr(i+1);
		m = exp[i];
		
		int leftTrue = findMaxParens(true, l);
		int rightTrue = findMaxParens(true, r);
		int rightFalse = findMaxParens(false, r);
		int leftFalse = findMaxParens(false, l);
		
		int total = (leftTrue + leftFalse) * (rightTrue+rightFalse);
		
		int totalTrue;
		if(m == "^")
		{
			totalTrue = rightTrue * leftFalse + rightFalse*leftTrue;
		}
		else if(m == "|")
		{
			totalTrue = rightTrue*leftFalse + rightFalse*leftTrue + 
				    leftTrue*rightTrue;
		}
		else
		{
			totalTrue = rightTrue*leftTrue;
		}
		if(val)
			ret+=totalTrue;
		else
			ret += total-totalTrue;
	}
	return ret;
}
int main()
{
	std::cout<<findMaxParens(true, "0&0&0&1^1|0")<<std::endl;
}
