#include<iostream>
#include<vector>
#include<algorithm>
int mul(int one, int two)
{
        int ret = 0;
        for(int i = 0; i<std::abs(two); i++)
                ret += one;
        return ret;
}
int sub(int one, int two)
{
	one += mul(-1,two);
	return one;
}
int divide(int one, int two)
{
	int result = 0;
	for(int i = two; i<=one; i += two)
	{
		result++;
	}
	return result;
}
int main()
{
	std::cout<<mul(10,5)<<" "<<sub(5, 2)<<" "<<divide(10, 2)<<std::endl;
}
