#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<vector>
std::mutex m;
std::vector<bool> stick(20);
std::vector<int> food(10);
void task(int pnumber)
{
	while(food[pnumber])
	{
		m.lock();
		if(!stick[pnumber] && !stick[2*pnumber])
	 	{
			stick[pnumber] = true;
			stick[pnumber*2] = true;
			food[pnumber]--;
			stick[pnumber] = false;
			stick[pnumber*2] = false;
			std::cout<<pnumber<<" "<<food[pnumber]<<std::endl;
		}
		m.unlock();
	}
}
int main()
{
	
	std::thread philosophers[10];
	for(auto it = food.begin(); it<food.end(); it++)
	{
		*it = 100;
	}
	for(int i = 0; i<10; i++)
	{
		philosophers[i] = std::thread(task, i);
	}
	for(int i = 0; i<10; i++)
	{
		philosophers[i].join();
	}
	return 0;
}
