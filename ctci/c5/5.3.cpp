#include<iostream>
#include<algorithm>
int flipToWin(int n)
{
	int zeroLoc = -1, count = 0, maxcount = 0;
	std::string s = "";
	for(int i = 31; i>= 0; i--)
	{
		bool num = (((1<<i) & n) != 0);
		if(num)
			s+="1";
		else
			s+="0";
	}
	std::cout<<s<<std::endl;
	std::reverse(s.begin(), s.end());
	for(int i = 0; i<32; i++)
	{
		if(s[i] == '1')
			count++;
		else
		{
			if(zeroLoc == -1)
			{
				count++;
				zeroLoc = i;
			}
			else
			{
				i = zeroLoc+1;
				if(maxcount < count)
					maxcount= count;
				zeroLoc = -1;
				count = 0;
			}
		}
	}
	return maxcount;
}
int main()
{
	std::cout<<flipToWin(1775)<<std::endl;
}
