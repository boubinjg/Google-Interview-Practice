#include<thread>
#include<mutex>
#include<iostream>
#include<queue>
std::queue<int> q;
std::mutex m;
void t1()
{
		while(true)
		{
			m.lock();
			if(q.front() == 101)
			{
				m.unlock();	
				break;
			}
			int i = q.front();
			if(i%3 == 0 && i%5 != 0)
			{
				std::cout<<"FIZZ"<<i<<std::endl;
				q.pop();
			}
			m.unlock();
		}
}
void t2()
{
		while(true)
		{
			m.lock();
			if(q.front() == 101)
			{
				m.unlock();
				break;
			}
			int i = q.front();
			if(i%3 != 0 && i%5 == 0)
			{
				std::cout<<"BUZZ"<<i<<std::endl;
				q.pop();
			}
			m.unlock();
		}
}
void t3()
{
		while(true)
		{
			m.lock();
			if(q.front() == 101)
			{
				m.unlock();
				break;
			}
			int i = q.front();
			if(i%3 == 0 && i%5 == 0)
			{
				std::cout<<"FIZZBUZZ"<<i<<std::endl;
				q.pop();
			}
			m.unlock();
		}

}
void t4()
{
		while(true)
		{
			m.lock();
			if(q.front() == 101)
			{
				m.unlock();
				break;
			}
			int i = q.front();
			if(i%3 != 0 && i%5 != 0)
			{
				std::cout<<i<<std::endl;
				q.pop();
			}
			m.unlock();
		}
}
void task(int tid)
{
	switch(tid)
	{
		case 0:
			t1();
			break;
		case 1:
			t2();
			break;
		case 2:
			t3();
			break;
		case 3:
			t4();
			break;
	}
}
int main()
{
	std::thread fb[4];
	for(int i = 1; i<=101; i++)
		q.push(i);
	
	for(int i = 0; i<4; i++)
		fb[i] = std::thread(task, i);
	
	for(int i = 0; i<4; i++)
		fb[i].join();
}
