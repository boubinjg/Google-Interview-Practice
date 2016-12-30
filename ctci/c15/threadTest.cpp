#include<iostream>
#include<string>
#include<thread>
#include<mutex>
std::mutex m;
void task(std::string message)
{
	m.lock();
	std::cout<<message<<std::endl;
	m.unlock();
}
int main()
{
	std::thread t[10];
	for(int i = 0; i<10; i++)
	{
		t[i] = std::thread(task, "Hello");
	}
	for(int i = 0; i<10; i++)
	{
		t[i].join();
	}
	return 0;
}
