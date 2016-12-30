#include<iostream>
#include<thread>

bool done[3];
int cnum = 0;

void three()
{	
	int onum = 0;
	while(cnum <= 100)
	{
		while(cnum == onum)
		{
			
		}
		onum = cnum;
		if(!(cnum %3) && cnum%5)
			std::cout<<cnum<<"Fizz"<<std::endl;
		done[0] = true;
	}
}
void five()
{
	int onum = 0;
	while(cnum <= 100)
	{
		while(cnum == onum)
		{
			
		}
		onum = cnum;
		if(!(cnum %5) && cnum%3)
			std::cout<<cnum<<"Buzz"<<std::endl;
		done[1] = true;
	}
}
void threeFive()
{
	int onum = 0;
	while(cnum <= 100)
	{
		while(cnum == onum)
		{
			
		}
		onum = cnum;
		if(!(cnum %5) && !(cnum%3))
			std::cout<<cnum<<"FizzBuzz"<<std::endl;
		done[2] = true;
	}
}
void nums()
{
	for(int i = 1; i<=101; i++)
	{
		cnum = i;
		while(!(done[0]&&done[1]&&done[2]))
		{
			
		}
		done[0] = false;
		done[1] = false;
		done[2] = false;	
	}
}

int main()
{
	std::thread t[4];
	t[0] = std::thread(nums);
	t[1] = std::thread(three);
	t[2] = std::thread(five);
	t[3] = std::thread(threeFive);
	for(int i = 0; i<4; i++)
		t[i].join();	
}
