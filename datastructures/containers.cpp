#include <iostream>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <unordered_map>
int main()
{
	std::vector<int> vector;
	vector.push_back(1);
	std::cout<<"vector first element: "<<vector[0]<<std::endl;
	
	std::deque<int> deque;
	deque.push_back(1);
	deque.push_front(2);
	std::cout<<"deque first element: "<<deque.front()<<" deque last element: "<<deque.back()<<std::endl;
	
	std::forward_list<int> fl;
	fl.push_front(1);
	fl.push_front(2);
	std::cout<<"front_list first element: "<<fl.front()<<std::endl;	

	std::list<int> list;
	list.push_back(1);
	list.push_front(2);
	std::cout<<"list first element: "<<list.front()<<std::endl;
	
	std::stack<int> stack;
	stack.push(1);
	std::cout<<"stack top element: "<<stack.top()<<std::endl;	

	std::queue<int> queue;
	queue.push(1);
	queue.push(2);
	std::cout<<"queue first element out: "<<queue.front()<<std::endl;

	auto cmp = [](int left, int right) {return (left < right);};
	std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
	pq.push(1);
	pq.push(2);
	pq.push(100);
	pq.push(5);
	std::cout<<"pq greatest elememt: "<<pq.top()<<std::endl;

	std::unordered_map<int, int> m;
	m.insert({{1,1},{1,2}});
	std::unordered_map<int,int>::const_iterator got = m.find(1);
	std::cout<<"Value at key 1 in unordered map "<<got->second<<std::endl;
}

