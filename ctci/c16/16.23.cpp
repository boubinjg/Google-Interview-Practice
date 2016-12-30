#include<iostream>
#include<vector>
#include<random>
int rand5()
{
	return std::rand()%5;
}
int rand7()
{
	int ret = 0;
	do{
		ret = 5*rand5() + rand5();
	}while(ret > 20);
	return ret%7;	
}
int main()
{
	std::vector<int> count(7);
	for(int j = 0; j<10000000; j++)
		count[rand7()]++;
	for(int i = 0; i<7; i++)
		std::cout<<count[i]<<std::endl;
	return 0;
}
