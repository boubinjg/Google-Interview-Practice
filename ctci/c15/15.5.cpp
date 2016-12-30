#include<mutex>
#include<thread>
#include<iostream>
int next = 1;
std::mutex m;
void funcA(int tid)
{
	m.lock();
	std::cout<<tid<<" called func A"<<std::endl;
	next++;
	m.unlock();
}
void funcB(int tid)
{
	m.lock();
	while(next != 2)
		wait(m);
	std::cout<<tid<<" called func B"<<std::endl;
	next++;
	m.unlock();
}
void funcC(int tid)
{
	while(next != 3)
		wait(m);
	std::cout<<tid<<" called func C"<<std::endl;
	m.unlock();
}
void task(int tid)
{
	if(tid == 1)
		funcA(tid);
	else if(tid == 2)
		funcB(tid);
	else 
		funcC(tid);
}
int main()
{
	std::thread t[3];
	for(int i = 1; i<=3; i++)
		t[i-1] = std::thread(task, i);
	for(int i = 1; i<=3; i++)
		t[i-1].join();
	return 0;
}
