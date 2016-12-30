#include<iostream>
#include<string>
int countEval(bool b, std::string s)
{
	if(s.length() == 0) return 0;
	if(s.length() == 1) return s[0]-'0';
	
	int ways = 0;
	for(int i = 1; i<s.length(); i+=2)
	{
		char c = s[i];
		std::string left = s.substr(0,i);
		std::string right = s.substr(i+1);
		
		int leftTrue = countEval(true, left);
		int leftFalse = countEval(false, left);
		int rightTrue = countEval(true, right);
		int rightFalse = countEval(false, right);
		int total = (leftTrue+leftFalse) * (rightTrue+rightFalse);
		std::cout<<total<<std::endl;
		int totalTrue = 0;
		if(c == '^')
			totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
		else if(c == '&')
			totalTrue = leftTrue*rightTrue;
		else if(c == '|')
			totalTrue = leftTrue * rightTrue + leftFalse * rightTrue + leftTrue * rightFalse;
		
		//std::cout<<totalTrue<<" "<<total<<std::endl;
		int subWays = b ? totalTrue : total-totalTrue;
		ways += subWays;
	}
	return ways;
}
int main()
{
	std::string test = "1&1&1";
	std::cout<<countEval(true, test)<<std::endl;
}
