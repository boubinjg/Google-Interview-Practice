#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
void printBoard(std::vector<std::string> b)
{
	for(int i = 0; i<b.size(); i++)
		std::cout<<b[i]<<std::endl;
}
bool checkString(std::string s)
{
	std::string sorted = s; 
	std::sort(sorted.begin(), sorted.end());
	if(sorted != "01234567")
		return false;

	for(int i = 0; i<8; i++)
		for(int j = i+1; j<8; j++)
		{	
			int val1 = s[i] - '0', val2 = s[j] - '0';
			if(val1 + j-i == val2)
				return false;
		}
	for(int i = 0; i<8; i++)	
		for(int j = i+1; j<8; j++)
		{
			int val1 = s[i] - '0', val2 = s[j] - '0';
			if(val1 - j + i == val2)
				return false;
		}
	return true;
}
int nQueens(std::string s)
{
	int count = 0;
	while(s != "77777777")
	{
		s[7]++;
		for(int i = 8; i>0; i--)
		{
			if(s[i] > '7')
			{
				s[i] = '0';
				s[i-1] ++;
			}
		}
		if(checkString(s))
		{
			count++;
			std::cout<<s<<std::endl;
		}
	}
	std::cout<<count<<std::endl;
}
void test()
{
	std::string s = "75462031";
	for(int i = 0; i<8; i++)
		for(int j = i+1; j<8; j++)
		{	
			int val1 = s[i] - '0', val2 = s[j] - '0';
			if(val1 + j-i == val2)
				std::cout<<"yes"<<std::endl;
		}
	for(int i = 0; i<8; i++)	
		for(int j = i+1; j<8; j++)
		{
			int val1 = s[i] - '0', val2 = s[j] - '0';
			std::cout<<val1<<" "<<val2<<" "<<val1-j+i<<std::endl;
			if(val1 - j + i == val2)
				std::cout<<"yes"<<std::endl;
		}

}
int main()
{
	nQueens("00000000");
}
