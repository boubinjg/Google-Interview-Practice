#include <iostream>
#include <vector>
#include <iterator>
class bheap {
private:
	std::vector<int> heap;
	int left(int parent)	
	{
		int l = 2 * parent + 1;
		if(l < heap.size())
			return l;
		else
			return -1;
	}
	int right(int parent)
	{
		int r = 2*parent + 2;
		if(r < heap.size())
			return r;
		else
			return -1;
	}
	int parent(int child)
	{
		int p = (child -1)/2;
		if(child == 0)
			return -1;
		else
			return p;
	}
	void heapifyup(int index)
	{
		if(index >= 0 && parent(index) >= 0 && heap[parent(index)] > heap[index])
		{
			int temp = heap[index];
			heap[index] = heap[parent(index)];
			heap[parent(index)] = temp;
			heapifyup(parent(index));
		}
	}
	void heapifydown(int index)
	{	
		int childl = left(index);
		int childr = right(index);
		if(childl >= 0 && childr >= 0 && heap[childl] >  heap[childr])
		{
			childl = childr;
		}
		if(childl > 0)
		{
			int temp = heap[index];
			heap[index] = heap[childl];
			heap[childl] = temp;
			heapifydown(childl);
		}
	}
public:
	bheap()
	{
		
	}
	void insert(int element)
	{
		heap.push_back(element);
		heapifyup(heap.size() - 1);
	}
	void deletemin()
	{
		if(heap.size() == 0)
			return;
		heap[0] = heap.at(heap.size() -1);
		heap.pop_back();
		heapifydown(0);
	}
	int extractmin()
	{
		std::cout<<std::endl;
		if(heap.size() == 0)
			return -1;
		else
			return heap.front();
	}
	void displayheap()
	{
		for(int i = 0; i<heap.size(); i++)
			std::cout<<heap[i]<<" ";
		std::cout<<std::endl;
	}
	int size()
	{
		return heap.size();
	}
};
int main()
{
	bheap h;
	h.insert(5);
	h.insert(1);
	h.insert(100);
	h.insert(2);
	std::cout<<h.extractmin()<<" "<<h.size()<<std::endl;
}
