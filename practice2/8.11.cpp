#include<iostream>
int waysToMake(int dec, int total)
{
	int ndec, ret = 0;
	if(dec == 1)
		return 1;
	if(dec == 25)	
		ndec=10;
	else if(dec == 10)
		ndec = 5;
	else
		ndec = 1;
	
	for(; total>=0; total-=dec)
	{
		ret += waysToMake(ndec, total);
	}
	return ret;
}
int main()
{
	std::cout<<waysToMake(25, 100)<<std::endl;
}
